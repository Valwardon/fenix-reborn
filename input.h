#ifndef GUI_H
#define GUI_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

bool handle_input();
bool handle_input();
bool init_input();
void cleanup_input(); // Declare the cleanup_input() function

#define MAX_MACRO_LENGTH 1000
#define MAX_COMMAND_LENGTH 20

void perform_macro(char* macro);

#endif /* GUI_H */
