#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils.h"

// Load configuration from a file
int load_config(void) {
    FILE *file;
    char line[256];
    char *key, *value;

    // Open the configuration file for reading
    file = fopen("config.ini", "r");
    if (!file) {
        fprintf(stderr, "Failed to open configuration file\n");
        return 0;
    }

    // Read each line of the file and parse the key-value pairs
    while (fgets(line, sizeof(line), file)) {
        // Ignore comments and blank lines
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        // Split the line into a key-value pair
        key = strtok(line, "=");
        value = strtok(NULL, "\n");

        // Update the configuration values based on the key
        if (strcmp(key, "threshold") == 0) {
            threshold = atoi(value);
        } else if (strcmp(key, "recording_duration") == 0) {
            recording_duration = atoi(value);
        }
    }

    // Close the configuration file
    fclose(file);

    return 1;
}

// Get the threshold value
int get_threshold(void) {
    return threshold;
}

// Get the recording duration value
int get_recording_duration(void) {
    return recording_duration;
}
