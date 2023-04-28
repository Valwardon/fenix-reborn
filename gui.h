#ifndef GUI_H
#define GUI_H

#include <stdbool.h>
#include <Windows.h>

void cleanup_gui(void);


#define IDC_STATUS_BAR 1001

// Initialize the GUI
bool init_gui(void);

// Update the GUI
void update_gui(void);

// Show a message box
void show_message_box(const char *title, const char *message);

#endif /* GUI_H */
