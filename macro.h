#ifndef MACRO_H
#define MACRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int macro_init(void);
int macro_perform(struct Macro* macro); // forward declaration
void macro_cleanup(void);

#define MAX_MACRO_LEN 1000
#define MAX_MACRO_NAME_LEN 50

// Function definition
void cleanup_macros(void) {
    // Function body
}

void run_macros(void);

typedef struct {
    char name[MAX_MACRO_NAME_LEN];
    int len;
    INPUT inputs[MAX_MACRO_LEN];
} Macro;

Macro* create_macro(char* name, int len, INPUT inputs[]);
void delete_macro(Macro* macro);
Macro* find_macro(char* name);

#endif
