#  :'######::'##:::::'##:'########:'########:'########::
#  '##... ##: ##:'##: ##: ##.....:: ##.....:: ##.... ##:
#   ##:::..:: ##: ##: ##: ##::::::: ##::::::: ##:::: ##:
#  . ######:: ##: ##: ##: ######::: ######::: ########::
#  :..... ##: ##: ##: ##: ##...:::: ##...:::: ##.....:::
#  '##::: ##: ##: ##: ##: ##::::::: ##::::::: ##::::::::
#  . ######::. ###. ###:: ########: ########: ##::::::::
#  :......::::...::...:::........::........::..:::::::::

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
TAP_DANCE_ENABLE = yes

EXTRAFLAGS += -flto

# Chording / Combos
COMBO_ENABLE = yes
INTROSPECTION_KEYMAP_C = helpers/introspection_keymap.c

SRC += getreuer/layer_lock/layer_lock.c \
	getreuer/sentence_case/sentence_case.c \
	getreuer/sentence_case/override.c \
	combos/combos.c \
	config/config.c \
	generated/correct_chords.c \
	generated/cycles.c \
	helpers/graphite.c \
	helpers/helpers.c \
	helpers/temporary_message.c \
	magic/cycling_combos.c \
	magic/magic.c \
	magic/repeat.c \
	oled/luna.c \
	oled/modifiers.c \
	oled/oled.c \
	oled/pixel_arts.c \
	oled/wpm.c \
	shortcuts/shortcuts.c \
	symbols/accents.c \
	symbols/symbols.c \
	selection/selection.c \
	jump_cursor/jump.c \
	tap_dance/tap_dance.c \
	teacher/chord_teacher.c

# oled/clock.c

# correction/virt_sidechannel.c
