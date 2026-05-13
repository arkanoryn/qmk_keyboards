import global_variables
import common

def write_combos_header(enums, prog_arrays):
    externs = []
    for array in prog_arrays:
        # Extract just the array name (remove the const uint16_t PROGMEM part and the = {...} part)
        # array looks like: "const uint16_t PROGMEM GRAPHITE_DEL_WORD_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_BSPC, COMBO_END};"
        # First remove the prefix
        no_prefix = array.replace("const uint16_t PROGMEM ", "")
        # Then split on "[] = {" to get the array name
        array_name = no_prefix.split("[] = {")[0]
        # Filter out sentinel enum names (start with underscore) which are NOT arrays
        if not array_name.startswith("_"):
            externs.append(f"extern const uint16_t PROGMEM {array_name}[];")
    
    content = common.lines(
        common.HEADER_HFILE,
        "#include QMK_KEYBOARD_H",
        '#include "farkann_v2.h"',
        "",
        "enum combos {",
        chr(10).join(enums),
        "};",
        "",
        "// Extern declarations for combo PROGMEM arrays",
        chr(10).join(externs),
        "",
        "const char* get_combos_cmds(uint16_t combo_index);",
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.COMBOS_FILENAME}.h").open("w") as file:
        file.write(content)

def write_combos_cfile(progs, combos_t, cmds):
    content = common.lines(
        common.HEADER_CFILE,
        "#include QMK_KEYBOARD_H",
        f'#include "{global_variables.COMBOS_FILENAME}.h"',
        "",
        f"{'\n'.join(progs)}",
        "",
        f"{'\n'.join(cmds)}",
        "",
        "const char* get_combos_cmds(uint16_t combo_index){",
        "    return combo_cmds[combo_index];",
        "};",
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.COMBOS_FILENAME}.c").open("w") as file:
        file.write(content)

def write_keymap_combos_inc(combos_t):
    """Generate keymap_combos.inc file with combo_t array entries"""
    content = f"{'\n'.join(combos_t)}"
    
    with (global_variables.GENERATED_FOLDER / global_variables.KEYMAP_COMBOS_INC).open("w") as file:
        file.write(content)

# BUILD THE DATA

def build_combo_name(combo, prefix):
    """Build the combo name with prefix. Does NOT add _COMBO suffix."""
    return f"{prefix}_{combo[global_variables.NAME_POS]}"

def fill_enum(enums, prefix_combo):
    (prefix, combo) = prefix_combo
    name = build_combo_name(combo, prefix)
    enums.append(f"    {name},")

def fill_combos_prog(progs, prefix_combo):
    (prefix, combo) = prefix_combo
    keys = []
    name = build_combo_name(combo, prefix)

    for i, key in enumerate(combo):
        if i >= global_variables.KEYS_START_POS:
            keys.append(f"{prefix}_{key}")

    progs.append(f"const uint16_t PROGMEM {name}_COMBO[] = {{{', '.join(keys)}, COMBO_END}};")

def is_action_combo(combo):
    """Check if combo is an ACTION type combo (uses COMBO macro with a keycode)"""
    is_action = combo[global_variables.IS_ACTION_POS]
    # ACTION means use COMBO(keycode), NOT ACTION means use COMBO_ACTION
    return is_action == "ACTION"

def fill_combos_t(combos_t, prefix_combo):
    (prefix, combo) = prefix_combo
    name = build_combo_name(combo, prefix)
    
    if is_action_combo(combo):
        action_key = combo[global_variables.STR_POS]
        combos_t.append(f"    COMBO({name}_COMBO, {action_key}),   /* [{name}] - ACTION type */")
    else:
        combos_t.append(f"    COMBO_ACTION({name}_COMBO),   /* [{name}] */")

def fill_combos_cmds(cmds, prefix_combo):
    (prefix, combo) = prefix_combo
    name = build_combo_name(combo, prefix)

    if combo[global_variables.IS_ACTION_POS] != "ACTION":
        if combo[global_variables.STR_POS]:
            cmds.append(f'    [{name}] = "{combo[global_variables.STR_POS]}",')
        else:
            cmds.append(f'    [{name}] = "",')

def generate_with_sentinels(all_combos):
    """Generate combo files with per-layout sentinels"""
    print("generate_combos - start")
    
    # Separate combos by layout
    combos_by_layout = {}
    for (layout, combo) in all_combos:
        if layout not in combos_by_layout:
            combos_by_layout[layout] = []
        combos_by_layout[layout].append((layout, combo))
    
    # Generate enum with sentinels
    all_enums = []
    all_progs = []
    all_combos_t = []
    all_cmds = []
    keymap_combos_t = []
    
    combo_index = 0
    first_combo_id = True
    
    for layout in global_variables.LAYOUTS:
        if layout in combos_by_layout:
            layout_combos = combos_by_layout[layout]
            
            # Add FIRST sentinel
            if first_combo_id:
                all_enums.append(f"    _FIRST_{layout}_COMBO = _FIRST_COMBO_ID,")
                first_combo_id = False
            else:
                # For subsequent layouts, FIRST sentinel = previous LAST + 1
                all_enums.append(f"    _FIRST_{layout}_COMBO,")
            
            # Add all combos for this layout
            for i, (l, combo) in enumerate(layout_combos):
                # Enum
                name = build_combo_name(combo, l)
                all_enums.append(f"    {name},")
                
                # PROGMEM arrays
                fill_combos_prog(all_progs, (l, combo))
                
                # combo_t entries
                fill_combos_t(all_combos_t, (l, combo))
                fill_combos_t(keymap_combos_t, (l, combo))  # Same format for keymap
                
                # Commands
                fill_combos_cmds(all_cmds, (l, combo))
                
                combo_index += 1
            
            # Add LAST sentinel
            all_enums.append(f"    _LAST_{layout}_COMBO = _FIRST_{layout}_COMBO + {len(layout_combos) - 1},")
            all_enums.append("")
    
    # Add final sentinel
    all_enums.append("    COMBO_COUNT")
    
    # Write header
    write_combos_header(all_enums, all_progs)
    
    # Write C file with PROGMEM arrays and cmd array
    cmds_content = [
        "static const char *combo_cmds[] = {",
        *all_cmds,
        "};",
        ""
    ]
    write_combos_cfile(all_progs, all_combos_t, cmds_content)
    
    # Write keymap_combos.inc
    write_keymap_combos_inc(keymap_combos_t)
    
    print("generate_combos - end")

def generate(all_combos):
    """Entry point for compatibility with existing code"""
    generate_with_sentinels(all_combos)
