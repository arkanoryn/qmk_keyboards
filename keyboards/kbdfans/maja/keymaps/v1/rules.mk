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
# CAPS_WORD_ENABLE = yes
# REPEAT_KEY_ENABLE = yes
# LEADER_ENABLE = yes
# Chording / Combos
# COMBO_ENABLE = yes

# INTROSPECTION_KEYMAP_C = generated/combos.c

SRC += getreuer/layer_lock/layer_lock.c \
	getreuer/select_word/select_word.c \
	getreuer/sentence_case/sentence_case.c \
	getreuer/sentence_case/override.c \
	helpers/helpers.c \
	helpers/graphite.c \
	helpers/temporary_message.c \
	shortcuts/shortcuts.c

# config/config.c \
# generated/cycles.c \
# generated/correct_chords.c \
# combos/combos.c \
# magic/cycling_combos.c \
# magic/magic.c \
# magic/repeat.c \
# teacher/chord_teacher.c \
# symbols/symbols.c \
# symbols/accents.c \
# oled/oled.c \
# oled/luna.c \
# oled/pixel_arts.c \
# oled/modifiers.c \
# oled/wpm.c

# oled/clock.c

# correction/virt_sidechannel.c
