#  '##::::'##::::'###::::::::::'##::::'###::::
#   ###::'###:::'## ##::::::::: ##:::'## ##:::
#   ####'####::'##:. ##:::::::: ##::'##:. ##::
#   ## ### ##:'##:::. ##::::::: ##:'##:::. ##:
#   ##. #: ##: #########:'##::: ##: #########:
#   ##:.:: ##: ##.... ##: ##::: ##: ##.... ##:
#   ##:::: ##: ##:::: ##:. ######:: ##:::: ##:
#  ..:::::..::..:::::..:::......:::..:::::..::

EXTRAFLAGS += -flto

# increase build time but reduce size
LTO_ENABLE = yes

# DEFERRED_EXEC_ENABLE = yes

# Self settings
OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
# Chording / Combos
COMBO_ENABLE = yes

INTROSPECTION_KEYMAP_C = generated/combos.c

SRC += getreuer/layer_lock/layer_lock.c \
	getreuer/select_word/select_word.c \
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
	shortcuts/shortcuts.c \
	symbols/accents.c \
	symbols/symbols.c \
	teacher/chord_teacher.c

