# Copyright 2025-2026 Ark'Anoryn (@arkanoryn)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Build configuration for v2 keymap

# QMK standard options
LTO_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
# WPM_ENABLE = yes

# Core features
OS_DETECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
LAYER_LOCK_ENABLE = yes
# LEADER_ENABLE = yes

# Combo support
COMBO_ENABLE = yes
INTROSPECTION_KEYMAP_C = features/combos/generated/combos.c

# Future feature sources
SRC += features/repeat/repeat.c \
features/repeat/magic_graphite.c \
features/repeat/magic_sturdy.c \
features/repeat/magic_colemak.c \
features/repeat/magic_qwerty.c \
features/actions/actions.c \
features/accents/accents.c \
features/selection/selection.c \
features/jump_cursor/jump.c \
features/tap_dance/tap_dance.c

# Combo sources
SRC += features/combos/combos.c \
       helpers/helpers.c

# Process record sources
SRC += process_record.c

# Getreuer library sources
SRC += users/v2/lib/getreuer/select_word/select_word.c \
       users/v2/lib/getreuer/sentence_case/sentence_case.c \
       users/v2/lib/getreuer/sentence_case/override.c

# Add cycling combos (conditional)
ifeq ($(strip $(CYCLE_COMBO_ENABLE)),yes)
SRC += features/cycling_combos/cycling_combos.c
endif

# Add chord teacher (conditional)
ifeq ($(strip $(CHORD_TEACHER_ENABLE)),yes)
SRC += features/chord_teacher/chord_teacher.c
endif

#   combos/combos.c \
# 	helpers/helpers.c \
# 	helpers/graphite.c \
# 	symbols/symbols.c \
# 	selection/selection.c \
# 	tap_dance/tap_dance.c \
# 	magic/magic.c

# Advanced compiler optimization
EXTRAFLAGS += -flto=auto
