import global_variables
import common

def write_correct_chords(correct_chords):
    statements = []

    for chord in correct_chords:
        name, keys = chord
        statements.append("  if (strcmp(\"{name} \", buffer) == 0) {{ return \"{keys}\"; }}".format(name=name, keys=keys))
        fn_prototype = "char *check_chord(char *buffer)"

    c_content = common.lines(
        common.HEADER_CFILE,
        "#include <string.h>",
        "",
        f"{fn_prototype} {{", # mind the {{
        "\n".join(statements),
        "  return NULL;",
        "}",
        ""
    )
    h_content = common.lines(
        common.HEADER_HFILE,
        f"{fn_prototype};", # mind the ;
        ""
    )

    with (global_variables.GENERATED_FOLDER / f"{global_variables.CORRECT_CHORD_FILENAME}.c").open("w") as file:
        file.write(c_content)
    with (global_variables.GENERATED_FOLDER / f"{global_variables.CORRECT_CHORD_FILENAME}.h").open("w") as file:
        file.write(h_content)

def generate_combos_teacher(combos):
    print("generate_teacher - start")
    correct_chords = []

    for (_prefix, combo) in combos:
        if (combo[global_variables.STR_POS] != "" and combo[global_variables.IS_ACTION_POS] != "ACTION"):
            keys = '+'.join(combo[global_variables.KEYS_START_POS:]).replace("QUOT", "'")
            correct_chords.append((combo[global_variables.STR_POS], keys))

    write_correct_chords(correct_chords)
    print("generate_teacher - done")
