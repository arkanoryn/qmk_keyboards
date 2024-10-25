LTO_ENABLE = yes

OS_DETECTION_ENABLE = yes

CAPS_WORD_ENABLE = yes

LEADER_ENABLE = yes
COMBO_ENABLE = yes

EXTRAFLAGS += -flto

SRC += features/layer_lock.c
