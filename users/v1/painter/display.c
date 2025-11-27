/* Copyright 2025 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef FARKANN_LCD_SCREEN

#include "qp_surface.h"
#include "painter/fonts/font_oled.qff.h"
#include "layers.h"
#include "display.h"
#include "teacher/chord_teacher.h"

static painter_device_t         display;
static painter_device_t         surface;
static uint8_t                  left_surface_buffer[SURFACE_REQUIRED_BUFFER_BYTE_SIZE(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, 16)];
static uint8_t                  right_surface_buffer[SURFACE_REQUIRED_BUFFER_BYTE_SIZE(FARKANN_SCREEN_2_WIDTH, FARKANN_SCREEN_2_HEIGHT, 16)];
static painter_font_handle_t    font_oled;

void init_display(painter_device_t current_display, painter_rotation_t rotation, uint16_t width, uint16_t height) {
    qp_init(current_display, rotation);
    qp_clear(current_display);
    qp_rect(current_display, 0, 0, width, height , 0, 0, 0, true);
    qp_power(current_display, true);
    qp_flush(current_display);
};

void    init_displays(void) {
    font_oled = qp_load_font_mem(font_oled_font);

    if (is_keyboard_left()) {
        surface = qp_make_rgb565_surface(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, left_surface_buffer);
        display = qp_st7735_make_spi_device(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, OLED_CS_PIN, OLED_DC_PIN, OLED_RST_PIN, FARKANN_SCREEN_SPI_DIVISOR, FARKANN_SCREEN_SPI_MODE);

        init_display(display, FARKANN_SCREEN_ROTATION, FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT);
        qp_init(surface, FARKANN_SCREEN_ROTATION);
        qp_rect(surface, 0, 0, FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, 0, 0, 0, true);
    } else {
        surface = qp_make_rgb565_surface(FARKANN_SCREEN_2_WIDTH, FARKANN_SCREEN_2_HEIGHT, right_surface_buffer);
        display = qp_st7735_make_spi_device(FARKANN_SCREEN_2_WIDTH, FARKANN_SCREEN_2_HEIGHT, OLED_CS_PIN, OLED_DC_PIN, OLED_RST_PIN, FARKANN_SCREEN_2_SPI_DIVISOR, FARKANN_SCREEN_2_SPI_MODE);

        qp_init(surface, FARKANN_SCREEN_2_ROTATION);
        init_display(display, FARKANN_SCREEN_2_ROTATION, FARKANN_SCREEN_2_WIDTH, FARKANN_SCREEN_2_HEIGHT);
        qp_rect(surface, 0, 0, FARKANN_SCREEN_2_WIDTH, FARKANN_SCREEN_2_HEIGHT, 0, 0, 0, true);
    }

    qp_surface_draw(surface, display, 0, 0, false);
};

void write_layout(void) {
    if (font_oled != NULL) {
        char *text;

        switch (get_highest_layer(layer_state)) {
            case _GRAPHITE:
                text = "Graphite";
                break;
            case _ACTIONS:
                text = "Actions";
                break;
            case _SYMBOLS:
                text = "Symbols";
                break;
            case _ACCENTS:
                text = "Accents";
                break;
            case _NUMPAD_SOUND:
                text = "Numpad and Sounds";
                break;
            case _CONFIG:
                text = "Config";
                break;
            case _QWERTY:
                text = "Qwerty";
                break;
            case _GAME:
                text = "Game";
                break;
            case _COLEMAK:
                text = "Colemak";
                break;
            case _STURDY:
                text = "Sturdy";
                break;
            case _FN:
                text = "Function";
                break;
            default:
                text = "??";
        }
        int16_t width = qp_textwidth(font_oled, text);
        qp_drawtext(surface, (FARKANN_SCREEN_WIDTH - width), (FARKANN_SCREEN_HEIGHT - font_oled->line_height), font_oled, text);
    }
};

#ifdef CHORD_TEACHER_ENABLE
void write_teacher_state(painter_font_handle_t font_oled) {
    if (font_oled != NULL) {
        char *text;

        if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_NORMAL) {
            text = "Teacher Mode: Normal";
        } else if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_CORRECTIVE) {
            text = "Teacher Mode: Corrective";
        } else if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) {
            text = "Teacher Mode: OFF";
        }

        int16_t width = qp_textwidth(font_oled, text);
        qp_drawtext(surface, (FARKANN_SCREEN_WIDTH - width), (FARKANN_SCREEN_HEIGHT - (font_oled->line_height * 2)), font_oled, text);
    }
}

void write_teacher_str(painter_font_handle_t font_oled) {
    if (font_oled != NULL) {
        char *text;
        text = get_teacher_chord_buffer();
        if (*text == '\0') {
            text = "                    ";
        }
        int16_t width = qp_textwidth(font_oled, text);
        qp_drawtext(surface, (FARKANN_SCREEN_WIDTH - width), (FARKANN_SCREEN_HEIGHT - font_oled->line_height), font_oled, text);
    }
}
#endif // CHORD_TEACHER_ENABLE

void draw_screen_left(void) {
#ifdef CHORD_TEACHER_ENABLE
    write_teacher_state(font_oled);
    write_teacher_str(font_oled);
#endif // CHORD_TEACHER_ENABLE
    // write_layout();
    qp_surface_draw(surface, display, 0, 0, false);
};

// #ifdef FARKANN_DOUBLE_SCREEN
void draw_screen_right(void) {
    if (font_oled != NULL) {
        char *text = "Right";
        int16_t width = qp_textwidth(font_oled, text);
        qp_drawtext(surface, (FARKANN_SCREEN_2_WIDTH - width), (FARKANN_SCREEN_2_HEIGHT - font_oled->line_height), font_oled, text);
    }

    qp_surface_draw(surface, display, 0, 0, false);
};
// #endif // FARKANN_DOUBLE_SCREEN

void    draw(void) {
    if (is_keyboard_left()) {
        draw_screen_left();
    } else {
        draw_screen_right();
    }
};
#endif // FARKANN_LCD_SCREEN

