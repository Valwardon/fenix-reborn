#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <stdbool.h>

// function prototypes
bool init_playback();
bool start_playback();
bool stop_playback();
void pause_playback();
void resume_playback();

void cleanup_playback(); // Add this line

typedef struct InputEvent InputEvent;

void play_macro(const char* macro_file_path);

#endif
