# Convert from Elite-C to Liatris
CONVERT_TO=liatris
# increase build time but reduce size
LTO_ENABLE = yes

# Self settings
RGB_MATRIX_ENABLE = yes
OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
# LEADER_ENABLE = yes

EXTRAFLAGS += -flto

# Chording / Combos
COMBO_ENABLE = yes
INTROSPECTION_KEYMAP_C = generated/combos.c

# DEFERRED_EXEC_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes

SRC += getreuer/layer_lock/layer_lock.c \
	getreuer/select_word/select_word.c \
	generated/cycles.c \
	generated/correct_chords.c \
	combos/combos.c \
	magic/cycling_combos.c \
	magic/magic.c \
	magic/repeat.c \
	teacher/chord_teacher.c \
	symbols/symbols.c \
	symbols/accents.c \
	shortcuts/shortcuts.c

# correction/virt_sidechannel.c
