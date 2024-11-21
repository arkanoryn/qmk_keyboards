import global_variables
import common

def write_combos_header(enums):
    tmp_enums = enums.copy()
    tmp_enums[0] = f"{tmp_enums[0]} = 0"

    content = common.lines(
        common.HEADER_HFILE,
        "#include QMK_KEYBOARD_H",
        "#include \"combos.h\"",
        "",
        "enum combos {",
        f"  {",\n  ".join(tmp_enums)}",
        "};",
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
        f"#include \"{global_variables.COMBOS_FILENAME}.h\"",
        "",
        f"{"\n".join(progs)}",
        "",
        "combo_t key_combos[] = {",
        f"  {",\n  ".join(combos_t)}",
        "};",
        "",
        "static const char *combo_cmds[] = {",
        f"  {",\n  ".join(cmds)}",
        "};",
        "",
        "const char* get_combos_cmds(uint16_t combo_index){",
        "    return combo_cmds[combo_index];",
        "};",
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.COMBOS_FILENAME}.c").open("w") as file:
        file.write(content)

# BUILD THE DATA

def build_combo_name(combo, prefix):
    return f"{prefix}_{combo[global_variables.NAME_POS]}"

def fill_enum(enums, prefix_combo):
    (prefix, combo) = prefix_combo
    name = build_combo_name(combo, prefix)

    enums.append(name)

def fill_combos_prog(progs, prefix_combo):
    (prefix, combo) = prefix_combo
    keys = []
    name = build_combo_name(combo, prefix)

    for i, key in enumerate(combo):
        if i >= global_variables.KEYS_START_POS:
            keys.append("{prefix}_{key}".format(prefix=prefix, key=key))

    progs.append(f"const uint16_t PROGMEM {name}_COMBO[] = {{{", ".join(keys)}, COMBO_END}};")

def fill_combos_t(combos_t, prefix_combo):
    (prefix, combo) = prefix_combo
    name = build_combo_name(combo, prefix)

    if combo[global_variables.IS_ACTION_POS] == "ACTION":
        combos_t.append(f"[{name}] = COMBO({name}_COMBO, {combo[global_variables.STR_POS]})")
    else:
        combos_t.append(f"[{name}] = COMBO_ACTION({name}_COMBO)")

def fill_combos_cmds(cmds, prefix_combo):
    (prefix, combo) = prefix_combo
    name = build_combo_name(combo, prefix)

    if combo[global_variables.IS_ACTION_POS] != "ACTION":
        cmds.append(f"[{name}] = \"{combo[global_variables.STR_POS]}\"")

def generate(combos):
    print("generate_combos - start")
    combos_enum = []
    combos_prog = []
    combos_t = []
    combos_cmds = []

    for index, prefix_combo in enumerate(combos):
        fill_enum(combos_enum, prefix_combo)
        fill_combos_prog(combos_prog, prefix_combo)
        fill_combos_t(combos_t, prefix_combo)
        fill_combos_cmds(combos_cmds, prefix_combo)

    write_combos_header(combos_enum)
    write_combos_cfile(combos_prog, combos_t, combos_cmds)
    print("generate_combos - end")
