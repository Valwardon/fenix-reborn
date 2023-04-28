#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"

bool file_exists(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

char* read_file_contents(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (!file) {
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate buffer for file contents
    char* file_contents = (char*) malloc(file_size + 1);
    if (!file_contents) {
        fclose(file);
        return NULL;
    }

    // Read file contents into buffer
    size_t bytes_read = fread(file_contents, 1, file_size, file);
    fclose(file);

    if (bytes_read < file_size) {
        free(file_contents);
        return NULL;
    }

    file_contents[file_size] = '\0';

    return file_contents;
}
