import os
import csv

import global_variables
import generate_combos
import generate_cycles
import generate_teacher

def valid_combo(combo):
    """Check if a row is a valid combo definition"""
    # Must have at least: NAME, STR, CAN_CYCLE, IS_ACTION, KEY1
    # Skip prefix lines, comment lines, and empty lines
    if not combo or len(combo) < 5:
        return False
    if combo[0].startswith("prefix") or combo[0].startswith("#"):
        return False
    # Skip empty names
    if not combo[0].strip():
        return False
    return True

def get_all_combos(descriptions_folder):
    combos = []
    for filename in os.listdir(descriptions_folder):
        with open(os.path.join(descriptions_folder, filename), 'r') as csvfile:
            csv_content = csv.reader(csvfile, delimiter=',')
            for row in csv_content:
                if valid_combo(row):
                    combos.append(row)
    return combos

def main():
    # Get all combo definitions from CSV files
    raw_combos = get_all_combos(global_variables.DESCRIPTIONS_FOLDER)
    
    # For each layout, create layout-prefixed combos
    all_combos = []
    for layout in global_variables.LAYOUTS:
        for combo in raw_combos:
            all_combos.append((layout, combo))
    
    # Generate all output files
    generate_combos.generate(all_combos)
    generate_cycles.generate(all_combos)
    generate_teacher.generate_combos_teacher(all_combos)

if __name__ == "__main__":
    main()
