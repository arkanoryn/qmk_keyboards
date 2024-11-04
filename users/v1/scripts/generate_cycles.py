import global_variables
import common
import generate_combos

def write_cycles_header(enums):
    tmp_enums = enums.copy()
    tmp_enums[0] = f"{tmp_enums[0]} = 0"

    content = common.lines(
        common.HEADER_HFILE,
        "typedef enum {",
        f"  {",\n  ".join(tmp_enums)},",
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
        f"#include \"{global_variables.COMBOS_FILENAME}.h\"",
        f"#include \"{global_variables.CYCLES_FILENAME}.h\"",
        "",
        "cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index) {",
        "  switch(combo_index) {",
        f"{"\n".join(matches)}",
        "  }",
        "  return _LAST_CYCLING_COMBO;",
        "};",
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.CYCLES_FILENAME}.c").open("w") as file:
        file.write(content)

def generate(combos):
    print("generate_cycles - start")
    cycles_enum = []
    matches = []

    for (prefix, combo) in combos:
        if combo[global_variables.CAN_CYCLE_POS] == "CIRCLE":
            cycle_name = combo[global_variables.NAME_POS]
            combo_name = generate_combos.build_combo_name(combo, prefix)

            cycles_enum.append(f"{cycle_name}")
            matches.append(f"    case {combo_name}: return {cycle_name};")

    write_cycles_header(cycles_enum)
    write_cycles_cfile(matches)
    print("generate_cycles - end")
