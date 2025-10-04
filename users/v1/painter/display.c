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

#include "img/dragon.qgf.h"
#include "display.h"

static painter_device_t display;

void    init_displays(void) {
    painter_image_handle_t dragon = qp_load_image_mem(gfx_dragon);
    display = qp_st7735_make_spi_device(FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, OLED_CS_PIN, OLED_DC_PIN, OLED_RST_PIN, FARKANN_SCREEN_SPI_DIVISOR, FARKANN_SCREEN_SPI_MODE);


    qp_init(display, FARKANN_SCREEN_ROTATION);
    qp_clear(display);
    qp_rect(display, 0, 0, FARKANN_SCREEN_WIDTH, FARKANN_SCREEN_HEIGHT, 0, 0, 0, true);
    if (dragon != NULL) {
        qp_drawimage(display, (FARKANN_SCREEN_WIDTH - dragon->width), (FARKANN_SCREEN_HEIGHT - dragon->height), dragon);
    }
};

void draw_screen_1(void) {
    for (int i = 0; i < 239; i+=8) {
        qp_rect(display, 0, i, 25, i+7, i, 255, 255, true);
        qp_flush(display);
    }
};

// #ifdef FARKANN_DOUBLE_SCREEN
void draw_screen_2(void) {
    for (int i = 0; i < 239; i+=8) {
        qp_circle(display, 32, 32+i, 4, i, 255, 255, true);
        qp_flush(display);
    }
};
// #endif // FARKANN_DOUBLE_SCREEN

void    draw(void) {
static uint32_t last_draw = 0;

    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();

        // if (is_keyboard_left()) {
        //     draw_screen_1();
        // } else {
        //     draw_screen_2();
        // }
    }
};
#endif // FARKANN_LCD_SCREEN

