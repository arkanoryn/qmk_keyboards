# Copyright 2025-2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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
LEADER_ENABLE = yes

# Combo support // TODO: future change
# COMBO_ENABLE = yes

# Future feature sources (commented out for now)
SRC += features/repeat/repeat.c \
features/repeat/magic_graphite.c \
features/repeat/magic_sturdy.c \
features/repeat/magic_colemak.c \
features/repeat/magic_qwerty.c \
features/actions/actions.c

#   combos/combos.c \
# 	helpers/helpers.c \
# 	helpers/graphite.c \
# 	symbols/symbols.c \
# 	selection/selection.c \
# 	tap_dance/tap_dance.c \
# 	magic/magic.c

# Advanced compiler optimization
EXTRAFLAGS += -flto=auto
