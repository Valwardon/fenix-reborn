#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

bool file_exists(const char* file_path);

char* read_file_contents(const char* file_path);

void cleanup_macros(void);
void cleanup_gui(void);

int fenix_reborn(int argc, char *argv[]) {
    // Call the function
    cleanup_macros();
     cleanup_gui();
    return 0;
}

#endif /* UTILS_H */
