LTO_ENABLE = yes

DEFERRED_EXEC_ENABLE = yes
WPM_ENABLE = yes

OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LEADER_ENABLE = yes
QUANTUM_PAINTER_SUPPORTS_256_PALETTE = yes

# Chording / Combos
COMBO_ENABLE = yes
INTROSPECTION_KEYMAP_C = generated/combos.c

EXTRAFLAGS += -flto=auto

SRC += getreuer/layer_lock/layer_lock.c \
	getreuer/select_word/select_word.c \
	getreuer/sentence_case/sentence_case.c \
	getreuer/sentence_case/override.c \
	config/config.c \
	helpers/helpers.c \
	helpers/graphite.c \
	helpers/temporary_message.c \
	img/dragon.qgf.c \
	generated/cycles.c \
	generated/correct_chords.c \
	combos/combos.c \
	magic/cycling_combos.c \
	magic/magic.c \
	magic/repeat.c \
	painter/display.c \
	teacher/chord_teacher.c \
	symbols/symbols.c \
	symbols/accents.c \
	shortcuts/shortcuts.c

# oled/clock.c

# correction/virt_sidechannel.c

