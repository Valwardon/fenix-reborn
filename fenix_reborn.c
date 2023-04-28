#include <stdio.h>
#include "config.h"
#include "gui.h"
#include "macro.h"
#include "input.h"
#include "overlay.h"
#include "playback.h"
#include "recording.h"
#include "utils.h"
#include "recording.h"
#include "macro.h"
#include "stdbool.h"

void cleanup_input();

bool init_input();
// Function prototype
void cleanup_macros(void);

// function prototype
bool init_macros();

int main(int argc, char *argv[]) {
    // Load configuration
    if (!load_config()) {
        fprintf(stderr, "Failed to load configuration.\n");
        return 1;
    }

    // Initialize the program components
    if (!init_gui()) {
        fprintf(stderr, "Failed to initialize GUI.\n");
        goto cleanup;
    }

    if (!init_macros()) {
        fprintf(stderr, "Failed to initialize macros.\n");
        goto cleanup;
    }

    if (!init_input()) {
        fprintf(stderr, "Failed to initialize input.\n");
        goto cleanup;
    }

    if (!init_overlay()) {
        fprintf(stderr, "Failed to initialize overlay.\n");
        goto cleanup;
    }

    if (!init_playback()) {
        fprintf(stderr, "Failed to initialize playback.\n");
        goto cleanup;
    }

    if (!init_recording()) {
        fprintf(stderr, "Failed to initialize recording.\n");
        goto cleanup;
    }

    // Enter the main program loop
    while (1) {
        // Handle user input
        if (!handle_input()) {
            fprintf(stderr, "Failed to handle input.\n");
            goto cleanup;
        }

        // Update the GUI
        update_gui();

        // Run any active macros
        run_macros();
    }

cleanup:
    // Cleanup before exiting
    cleanup_recording();
    cleanup_playback();
    cleanup_overlay();
    cleanup_input();
    cleanup_macros();
    cleanup_gui();

    return 1;
}

// function definition
bool init_macros() {
    // code goes here
    return true;
}
