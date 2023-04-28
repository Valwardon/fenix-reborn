#ifndef RECORDING_H
#define RECORDING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "constants.h"

void cleanup_recording();

typedef enum {
    MOUSE_MOVE,
    LEFT_CLICK,
    RIGHT_CLICK,
    MIDDLE_CLICK,
    LEFT_DOWN,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP,
    MIDDLE_DOWN,
    MIDDLE_UP,
    MOUSE_SCROLL,
    KEYBOARD_PRESS,
    KEYBOARD_RELEASE,
    WAIT
} ActionType;

typedef struct {
    ActionType type;
    int x;
    int y;
    int keycode;
    int wait_time;
    char text[MAX_TEXT_LEN];
} Action;

typedef struct {
    Action* actions;
    int num_actions;
} Recording;

Recording* create_recording();

void add_mouse_move_action(Recording* recording, int x, int y);

void add_left_click_action(Recording* recording);

void add_right_click_action(Recording* recording);

void add_middle_click_action(Recording* recording);

void add_left_down_action(Recording* recording);

void add_left_up_action(Recording* recording);

void add_right_down_action(Recording* recording);

void add_right_up_action(Recording* recording);

void add_middle_down_action(Recording* recording);

void add_middle_up_action(Recording* recording);

void add_mouse_scroll_action(Recording* recording, int amount);

void add_keyboard_press_action(Recording* recording, int key_code);

void add_keyboard_release_action(Recording* recording, int key_code);

void add_wait_action(Recording* recording, int duration_ms);

void save_recording_to_file(Recording* recording, const char* file_path);

Recording* load_recording_from_file(const char* file_path);

void free_recording(Recording* recording);

bool init_recording();

#endif /* RECORDING_H */
