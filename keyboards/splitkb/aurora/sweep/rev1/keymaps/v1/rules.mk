# Convert from Elite-C to Liatris
CONVERT_TO=liatris
# increase build time but reduce size
LTO_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_FONT_H = keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/oled/font.c
DEFERRED_EXEC_ENABLE = yes
WPM_ENABLE = yes

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
	getreuer/sentence_case/sentence_case.c \
	getreuer/sentence_case/override.c \
	generated/cycles.c \
	generated/correct_chords.c \
	combos/combos.c \
	magic/cycling_combos.c \
	magic/magic.c \
	magic/repeat.c \
	teacher/chord_teacher.c \
	symbols/symbols.c \
	symbols/accents.c \
	shortcuts/shortcuts.c \
	oled/oled.c \
	oled/luna.c \
	oled/pixel_arts.c \
	oled/modifiers.c \
	oled/wpm.c

# oled/clock.c

# correction/virt_sidechannel.c
