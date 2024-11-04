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
INTROSPECTION_KEYMAP_C = combos/generated_combos.c

# DEFERRED_EXEC_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes

SRC += getreuer/layer_lock/layer_lock.c \
	getreuer/select_word/select_word.c \
	combos/combos.c \
	magic/cycling_combos.c \
	magic/generated_cycles_enum.c \
	magic/magic.c \
	magic/repeat.c \
	teacher/chord_teacher.c \
	teacher/generated_correct_chords.c \
	symbols/symbols.c \
	symbols/accents.c \
	shortcuts/shortcuts.c

# correction/virt_sidechannel.c
