LTO_ENABLE = yes

OS_DETECTION_ENABLE = yes

CAPS_WORD_ENABLE = yes

LEADER_ENABLE = yes

EXTRAFLAGS += -flto

# Chording / Combos
COMBO_ENABLE = yes
# DEFERRED_EXEC_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes

SRC += features/layer_lock.c

VPATH += keyboards/gboards # required to make the combos through the .def files work
