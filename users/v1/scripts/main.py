import os
import csv

import global_variables
import generate_teacher

def valid_combo(combo):
    if (len(combo) > 0 and combo[0][0] != "#"):
        return True
    else:
        return False

def get_all_combos(descriptions_folder):
    combos = []
    for filename in os.listdir(descriptions_folder):
        with open(os.path.join(descriptions_folder, filename), 'r') as csvfile:
            csv_content = csv.reader(csvfile, delimiter=',')
            prefix = ""
            for row in csv_content:
                if row and row[0] == "prefix":
                    prefix = row[1]
                elif row and valid_combo(row):
                    combos.append((prefix, row))

    return combos

combos = get_all_combos(global_variables.DESCRIPTIONS_FOLDER)

generate_teacher.generate_combos_teacher(combos)
