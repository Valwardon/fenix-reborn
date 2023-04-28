#ifndef FENIX_REBORN_H
#define FENIX_REBORN_H

// Function declarations
int load_config(void); // Load configuration from file
void cleanup_gui(void); // Cleanup GUI resources
void cleanup_macros(void); // Cleanup macro resources
void cleanup_input(void); // Cleanup input resources
void cleanup_ocr(void); // Cleanup OCR resources
void cleanup_overlay(void); // Cleanup overlay resources
void cleanup_playback(void); // Cleanup playback resources
void cleanup_recording(void); // Cleanup recording resources

// Variable declarations
extern int config_loaded; // Flag indicating if configuration has been loaded

#endif