from pathlib import Path

DESCRIPTIONS_FOLDER = Path(__file__).parent / "definitions/"
GENERATED_FOLDER = Path(__file__).parent.parent / "generated"

CORRECT_CHORD_FILENAME = "correct_chords"
COMBOS_FILENAME = "combos"

# combos format is: [NAME,STR,CAN_CYCLE,IS_ACTION,KEYS...]
NAME_POS = 0
STR_POS = 1
CAN_CYCLE_POS = 2
IS_ACTION_POS = 3
KEYS_START_POS = 4
