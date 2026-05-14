import os
from pathlib import Path

DESCRIPTIONS_FOLDER = Path(__file__).parent / "definitions/"
# Output directory: users/v2/features/combos/generated/
GENERATED_FOLDER = Path(__file__).parent.parent.parent / "features" / "combos" / "generated"

CORRECT_CHORD_FILENAME = "correct_chords"
COMBOS_FILENAME = "combos"
CYCLES_FILENAME = "cycles"

# For keymap_combos.inc generation
KEYMAP_COMBOS_INC = "keymap_combos.inc"

# combos format is: [NAME,STR,CAN_CYCLE,IS_ACTION,KEYS...]
NAME_POS = 0
STR_POS = 1
CAN_CYCLE_POS = 2
IS_ACTION_POS = 3
KEYS_START_POS = 4

# Layout prefixes
LAYOUTS = ["GRAPHITE", "QWERTY", "STURDY", "COLEMAK"]
