import global_variables
import common
import generate_combos

def write_cycles_header(enums):
    content = common.lines(
        common.HEADER_HFILE,
        "typedef enum {",
        f"  {chr(10).join(enums)},",
        "  _LAST_CYCLING_COMBO",
        "} cycling_combos_e;",
        "",
        "cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index);",
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.CYCLES_FILENAME}.h").open("w") as file:
        file.write(content)

def write_cycles_cfile(matches):
    content = common.lines(
        common.HEADER_CFILE,
        f'#include "{global_variables.COMBOS_FILENAME}.h"',
        f'#include "{global_variables.CYCLES_FILENAME}.h"',
        "",
        "cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index) {",
        "  switch(combo_index) {",
        f"{chr(10).join(matches)}",
        "  }",
        "  return _LAST_CYCLING_COMBO;",
        "};",
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.CYCLES_FILENAME}.c").open("w") as file:
        file.write(content)

def is_circle_combo(combo):
    """Check if combo can cycle"""
    can_cycle = combo[global_variables.CAN_CYCLE_POS]
    return can_cycle == "CIRCLE" or can_cycle == "NO CIRCLE"

def generate(combos):
    print("generate_cycles - start")
    cycles_enum = []
    matches = []

    for (prefix, combo) in combos:
        if is_circle_combo(combo):
            cycle_name = f"{prefix}_{combo[global_variables.NAME_POS]}"
            combo_name = generate_combos.build_combo_name(combo, prefix)

            cycles_enum.append(f"    {cycle_name}")
            matches.append(f"    case {combo_name}: return {cycle_name};")

    write_cycles_header(cycles_enum)
    write_cycles_cfile(matches)
    print("generate_cycles - end")
