#pragma once

#include "teacher/chord_teacher.h"

#define frame_size 1024
typedef struct {
    teacher_chord_mode_e teacher_mode;
    char*                chord_buffer;
} oled_state_s;

void update_oled_state(void);
oled_state_s get_oled_state(void);
void user_sync_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);

bool process_oled_displays(uint16_t keycode, keyrecord_t *record);

// Mods status
void render_mods_status(void);

// CLOCK
void render_clock(uint8_t shift, uint8_t line);
uint32_t clock_callback(uint32_t trigger_time, void* cb_arg);
bool process_clock(uint16_t keycode, keyrecord_t* record);

// WPM
void render_wpm(void);

// PET
void render_luna(int LUNA_X, int LUNA_Y);
bool process_pet_status(uint16_t keycode, keyrecord_t *record);

// Glitch
void arasaka_draw(void);

// pixel arts
void render_flame(void);

// Default from Sweep
void render_space(void);
