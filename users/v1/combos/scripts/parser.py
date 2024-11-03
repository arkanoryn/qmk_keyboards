# script to generate the `combos_descriptions.c` for the keyboard
# takes in arguments the csv files you want to use
# see examples in `../definitions/`
import csv
import sys

NAME_POS = 0
STR_POS = 1
CAN_CYCLE_POS = 2
KEYS_START_POS = 3
CORRECT_CHORD_FILE_PATH = "../../teacher/generated_correct_chords.c"

combos_e = []
combos_prog = []
combos_t = []
combos_cmds = []
cycles_e = []
teacher = []

def valid_combo(combo):
    if (len(combo) > 0 and combo[0][0] != "#"):
        return True
    else:
        return False

def write_correct_chords(correct_chords):
    statements = []

    for chord in correct_chords:
        name, keys = chord
        statements.append("  if (strcmp(\"{name} \", buffer) == 0) {{ return \"{keys}\"; }}".format(name=name, keys=keys))

    content = """#include "quantum.h"
#include "ark_v1.h"

char *check_chord(char *buffer) {{
{statements}
  return NULL;
}}
    """.format(statements="\n".join(statements))

    with open(CORRECT_CHORD_FILE_PATH, "w") as file:
        file.write(content)

def generate_teacher(combos):
    correct_chords = []
    print("start generate_teacher")

    for combo in combos:
        if (valid_combo(combo) and combo[STR_POS] != ""):
            keys = '+'.join(combo[KEYS_START_POS:]).replace("QUOT", "'")
            correct_chords.append((combo[STR_POS], keys))

    write_correct_chords(correct_chords)

for filename in sys.argv:
    if filename != "parser.py":
        prefix = ""
        combos = []
        with open('../definitions/{filename}'.format(filename=filename), newline='') as csvfile:
            spamreader = csv.reader(csvfile, delimiter=',')
            for row in spamreader:
                if row and row[0] == "prefix":
                    prefix = row[1]
                elif row:
                    combos.append(row)
            csvfile.close()

        # for index, combo in enumerate(combos):
        #     name = "{prefix}_{combo_name}".format(prefix=prefix, combo_name=combo[NAME_POS])
        #     keys = []
        #     for i, key in enumerate(combo):
        #         if i > CAN_CYCLE_POS:
        #             keys.append("{prefix}_{key}".format(prefix=prefix, key=key))

        #     if combo[CAN_CYCLE_POS] == "circle":
        #         cycles_e.append(("{name} = 0".format(name=combo[NAME_POS]), index)) if cycles_e == [] else cycles_e.append((combo[NAME_POS], index))

            # combos_e.append("{name} = 0".format(name=name))if combos_e == [] else combos_e.append(name)
            # combos_prog.append("const uint16_t PROGMEM {name}_COMBO[] = {{{keys}, COMBO_END}};".format(name=name, keys=", ".join(keys)))
            # combos_t.append("[{name}] = COMBO_ACTION({name}_COMBO)".format(name=name))
            # combos_cmds.append("[{name}] = \"{cmd}\"".format(name=name, cmd=combo[STR_POS]))
            generate_teacher(combos)

# header_content = """/*
# ** /!\\ This file is generated with the script `combos/scripts/parser.py`
# ** Do NOT manually modify. Change / create files under `combos/definitions` and
# ** re-run the script: `python3 parser.py <filename>`
# ** ex:
# **
# **     $> python3 parser.py qwerty.csv
# */
# #pragma once
# #include "quantum.h"
# #include "combos.h"

# enum combos {{
#   {combos_e}
# }};

# const char* get_combos_cmds(uint16_t combo_index);
# """.format(combos_e=",\n  ".join(combos_e))

# header_file = open("../generated_combos.h", "w")
# header_file.write(header_content)
# header_file.close()

# combo_content = """/*
# ** /!\\ This file is generated with the script `combos/scripts/parser.py`
# ** Do NOT manually modify. Change / create files under `combos/definitions` and
# ** re-run the script: `python3 parser.py <filename>`
# ** ex:
# **
# **     $> python3 parser.py qwerty.csv
# */
# #include QMK_KEYBOARD_H
# #include "combos.h"

# {combos_prog}

# combo_t key_combos[] = {{
#   {combos_t}
# }};

# static const char *combo_cmds[] = {{
#   {cmds}
# }};

# const char* get_combos_cmds(uint16_t combo_index){{
#     return combo_cmds[combo_index];
# }};
# """.format(
#     combos_prog="\n".join(combos_prog),
#     combos_t=",\n  ".join(combos_t),
#     cmds=",\n  ".join(combos_cmds)
#     )

# combos_file = open("../generated_combos.c", "w")
# combos_file.write(combo_content)
# combos_file.close()

# cycles_content = """/*
# ** /!\\ This file is generated with the script `combos/scripts/parser.py`
# ** Do NOT manually modify. Change / create files under `combos/definitions` and
# ** re-run the script: `python3 parser.py <filename>`
# ** ex:
# **
# **     $> python3 parser.py qwerty.csv
# */
# #pragma once

# typedef enum {{
#   {cycles_e},
#   _LAST_CYCLING_COMBO
# }} cycling_combos_e;

# cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index);
# """.format(cycles_e=",\n  ".join(list(zip(*cycles_e))[0]))
# combos_file = open("../../magic/generated_cycles_enum.h", "w")
# combos_file.write(cycles_content)
# combos_file.close()

# matches = []
# for (name, id) in cycles_e:
#     matches.append("    case {id}: return {name};".format(name=name, id=id))

# matches_content = """/*
# ** /!\\ This file is generated with the script `combos/scripts/parser.py`
# ** Do NOT manually modify. Change / create files under `combos/definitions` and
# ** re-run the script: `python3 parser.py <filename>`
# ** ex:
# **
# **     $> python3 parser.py qwerty.csv
# */
# #include "generated_cycles_enum.h"

# cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index) {{
#   switch(combo_index) {{
# {matches}
#   }}
#   return _LAST_CYCLING_COMBO;
# }};
# """.format(matches="\n".join(matches)) # TODO: the first "match" contains "= 0". That's bad and needs to be removed
# combos_file = open("../../magic/generated_cycles_enum.c", "w")
# combos_file.write(matches_content)
# combos_file.close()
