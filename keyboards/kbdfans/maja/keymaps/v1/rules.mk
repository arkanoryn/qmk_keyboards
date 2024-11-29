#  '##::::'##::::'###::::::::::'##::::'###::::
#   ###::'###:::'## ##::::::::: ##:::'## ##:::
#   ####'####::'##:. ##:::::::: ##::'##:. ##::
#   ## ### ##:'##:::. ##::::::: ##:'##:::. ##:
#   ##. #: ##: #########:'##::: ##: #########:
#   ##:.:: ##: ##.... ##: ##::: ##: ##.... ##:
#   ##:::: ##: ##:::: ##:. ######:: ##:::: ##:
#  ..:::::..::..:::::..:::......:::..:::::..::
#  maja/v1/rules.mk

EXTRAFLAGS += -flto

# increase build time but reduce size
LTO_ENABLE = yes

DEFERRED_EXEC_ENABLE = yes

# Self settings
OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
# Chording / Combos
# COMBO_ENABLE = yes

INTROSPECTION_KEYMAP_C = tap_dance/tap_dance.c

SRC += getreuer/layer_lock/layer_lock.c \
rgb.c \
	config/config.c \
	generated/correct_chords.c \
	helpers/graphite.c \
	helpers/helpers.c \
	helpers/temporary_message.c \
	magic/magic.c \
	magic/repeat.c \
	shortcuts/shortcuts.c \
	symbols/accents.c \
	selection/selection.c \
	jump_cursor/jump.c \
	symbols/symbols.c

