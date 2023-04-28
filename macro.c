#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#include "macro.h"
#include "input.h"

#define MAX_MACRO_LENGTH 1000
#define MAX_COMMAND_LENGTH 20

void perform_macro(char* macro) {
    int len = strlen(macro);
    INPUT* inputs = malloc(len * sizeof(INPUT));

    int i;
    for (i = 0; i < len; i++) {
        if (macro[i] == ' ') {
            inputs[i].type = INPUT_KEYBOARD;
            inputs[i].ki.wVk = VK_SPACE;
            inputs[i].ki.dwFlags = 0;
        } else if (strcmp(macro + i, "left") == 0) {
            inputs[i].type = INPUT_KEYBOARD;
            inputs[i].ki.wVk = VK_LEFT;
            inputs[i].ki.dwFlags = 0;
            i += 3;
        } else if (strcmp(macro + i, "right") == 0) {
            inputs[i].type = INPUT_KEYBOARD;
            inputs[i].ki.wVk = VK_RIGHT;
            inputs[i].ki.dwFlags = 0;
            i += 4;
        } else if (strcmp(macro + i, "up") == 0) {
            inputs[i].type = INPUT_KEYBOARD;
            inputs[i].ki.wVk = VK_UP;
            inputs[i].ki.dwFlags = 0;
            i += 2;
        } else if (strcmp(macro + i, "down") == 0) {
            inputs[i].type = INPUT_KEYBOARD;
            inputs[i].ki.wVk = VK_DOWN;
            inputs[i].ki.dwFlags = 0;
            i += 4;
        } else if (strcmp(macro + i, "random") == 0) {
            int rand_num = rand() % 4;
            if (rand_num == 0) {
                inputs[i].type = INPUT_KEYBOARD;
                inputs[i].ki.wVk = VK_LEFT;
                inputs[i].ki.dwFlags = 0;
            } else if (rand_num == 1) {
                inputs[i].type = INPUT_KEYBOARD;
                inputs[i].ki.wVk = VK_RIGHT;
                inputs[i].ki.dwFlags = 0;
            } else if (rand_num == 2) {
                inputs[i].type = INPUT_KEYBOARD;
                inputs[i].ki.wVk = VK_UP;
                inputs[i].ki.dwFlags = 0;
            } else if (rand_num == 3) {
                inputs[i].type = INPUT_KEYBOARD;
                inputs[i].ki.wVk = VK_DOWN;
                inputs[i].ki.dwFlags = 0;
            }
            i += 5;
        } else if (strcmp(macro + i, "left_click") == 0) {
            inputs[i].type = INPUT_MOUSE;
            inputs[i].mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
            i += 9;
        } else if (strcmp(macro + i, "right_click") == 0) {
            inputs[i].type = INPUT_MOUSE;
            inputs[i].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
            i += 10;
        } else if (isalpha(macro[i])) {
            inputs[i].type = INPUT_KEYBOARD;
            inputs[i].ki.wVk = toupper(macro[i]);
            inputs[i].ki.dwFlags = 0;
        }
    }

SendInput(len, inputs, sizeof(INPUT));
free(inputs);
}
