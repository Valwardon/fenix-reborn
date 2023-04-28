#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
#include "input.h"
#define MAX_MACRO_LENGTH 1000
#define MAX_COMMAND_LENGTH 20

void cleanup_input() {
    // Put any necessary cleanup code here
}

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

int main() {
    srand(time(NULL));
char command[MAX_COMMAND_LENGTH];
char macro[MAX_MACRO_LENGTH] = "";

while (1) {
    printf("Enter a command (start, edit, exit): ");
    scanf("%s", command);

    if (strcmp(command, "start") == 0) {
        printf("Starting macro...\n");

        printf("Enter the macro: ");
        getchar(); // Consume newline
        fgets(macro, MAX_MACRO_LENGTH, stdin);
        macro[strcspn(macro, "\n")] = '\0'; // Remove trailing newline

        printf("Press enter to stop the macro...\n");
        perform_macro(macro);
    } else if (strcmp(command, "edit") == 0) {
        printf("Editing macro...\n");

        printf("Enter the new macro: ");
        getchar(); // Consume newline
        fgets(macro, MAX_MACRO_LENGTH, stdin);
        macro[strcspn(macro, "\n")] = '\0'; // Remove trailing newline
    } else if (strcmp(command, "exit") == 0) {
        printf("Exiting program...\n");
        break;
    } else {
        printf("Invalid command.\n");
    }
}

return 0;
}