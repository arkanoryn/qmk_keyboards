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
#include "painter/img/dragon.qgf.h"
#include "painter/fonts/font_oled.qff.h"
#include "layers.h"
#include "display.h"

static painter_device_t         display;
static painter_device_t         surface;
static uint8_t my_framebuffer[SURFACE_REQUIRED_BUFFER_BYTE_SIZE(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, 16)];
static painter_font_handle_t    font_oled;
static painter_image_handle_t   dragon;

void init_display(painter_device_t current_display, painter_rotation_t rotation) {
    qp_init(current_display, rotation);
    qp_clear(current_display);
    qp_rect(current_display, 0, 0, FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, 0, 0, 0, true);
    qp_power(current_display, true);
    qp_flush(current_display);
};

void    init_displays(void) {
    font_oled = qp_load_font_mem(font_oled_font);
    dragon = qp_load_image_mem(gfx_dragon);

    if (is_keyboard_left()) {
        surface = qp_make_rgb565_surface(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, my_framebuffer);
        display = qp_st7735_make_spi_device(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, OLED_CS_PIN, OLED_DC_PIN, OLED_RST_PIN, FARKANN_SCREEN_SPI_DIVISOR, FARKANN_SCREEN_SPI_MODE);

        init_display(display, FARKANN_SCREEN_ROTATION);
        qp_init(surface, FARKANN_SCREEN_ROTATION);
    } else {
        display   = qp_st7735_make_spi_device(FARKANN_SCREEN_2_WIDTH, FARKANN_SCREEN_2_HEIGHT, OLED_CS_PIN, OLED_DC_PIN, OLED_RST_PIN, FARKANN_SCREEN_2_SPI_DIVISOR, FARKANN_SCREEN_2_SPI_MODE);
        qp_init(surface, FARKANN_SCREEN_2_ROTATION);
    }
    qp_rect(surface, 0, 0, FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, 0, 0, 0, true);
    qp_surface_draw(surface, display, 0, 0, false);
};

void display_dragon(void) {
    if (dragon != NULL) {
        qp_drawimage(surface, (FARKANN_SCREEN_WIDTH - dragon->width), (FARKANN_SCREEN_HEIGHT - dragon->height), dragon);
    }
}

void write_layout(void) {
    if (font_oled != NULL) {
        char *text = "!";
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

void draw_screen_left(void) {
    display_dragon();
    write_layout();
    qp_surface_draw(surface, display, 0, 0, false);
    // for (int i = 0; i < 239; i+=8) {
        // qp_rect(display, 0, i, 10, i+7, i, 255, 255, true);
        // qp_flush(display);
    // }
};

// #ifdef FARKANN_DOUBLE_SCREEN
void draw_screen_right(void) {
    for (int i = 0; i < 239; i+=8) {
        // qp_circle(display, 32, 32+i, 4, i, 255, 255, true);
        // qp_flush(display);
    }
};
// #endif // FARKANN_DOUBLE_SCREEN

void    draw(void) {
static uint32_t last_draw = 0;

    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();

        if (is_keyboard_left()) {
            draw_screen_left();
        } else {
            draw_screen_right();
        }
    }
};
#endif // FARKANN_LCD_SCREEN

