#include <windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "gui.h"
#include "idfile.h"

// Main window handle
static HWND main_window = NULL;

// Controls
static HWND macro_editor = NULL;
static HWND record_button = NULL;
static HWND play_button = NULL;
static HWND status_bar = NULL;

// Window procedure for the main window
LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Create the macro editor
            macro_editor = CreateWindowEx(
                0, "EDIT", "",
                WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
                10, 10, 400, 500,
                hwnd, NULL, GetModuleHandle(NULL), NULL
            );
            if (!macro_editor) {
                fprintf(stderr, "Failed to create macro editor\n");
                return -1;
            }

            // Create the record button
            record_button = CreateWindowEx(
                0, "BUTTON", "Record",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                420, 10, 100, 30,
                hwnd, (HMENU)IDC_RECORD_BUTTON, GetModuleHandle(NULL), NULL
            );
            if (!record_button) {
                fprintf(stderr, "Failed to create record button\n");
                return -1;
            }

            // Create the play button
            play_button = CreateWindowEx(
                0, "BUTTON", "Play",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                420, 50, 100, 30,
                hwnd, (HMENU)IDC_PLAY_BUTTON, GetModuleHandle(NULL), NULL
            );
            if (!play_button) {
                fprintf(stderr, "Failed to create play button\n");
                return -1;
            }

            // Create the status bar
            status_bar = CreateWindowEx(
                0, STATUSCLASSNAME, NULL,
                WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
                0, 0, 0, 0,
                hwnd, (HMENU)IDC_STATUS_BAR, GetModuleHandle(NULL), NULL
            );
            if (!status_bar) {
                fprintf(stderr, "Failed to create status bar\n");
                return -1;
            }

            // Set the initial status bar text
            SendMessage(status_bar, SB_SETTEXT, 0, (LPARAM)"Ready");

            break;
        case WM_COMMAND:
            // Handle menu and control commands
            switch (LOWORD(wParam)) {
                case ID_FILE_EXIT:
                    PostMessage(hwnd, WM_CLOSE, 0, 0);
                    break;
                case IDC_RECORD_BUTTON:
                    // Handle record button click
                    break;
                case IDC_PLAY_BUTTON:
                    // Handle play button click
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// WinMain function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MSG msg;
    // Initialize COM
    if (FAILED(CoInitialize(NULL))) {
        fprintf(stderr, "Failed to initialize COM\n");
        return 1;
    }

    // Initialize the GUI
    if (!init_gui()) {
        fprintf(stderr, "Failed to initialize GUI\n");
        return 1;
    }

    // Main message loop
while (GetMessage(&msg, NULL, 0, 0)) {
// Check for keyboard accelerators
if (!TranslateAccelerator(main_window, NULL, &msg)) {
// Process the message
TranslateMessage(&msg);
DispatchMessage(&msg);
}
}
// Uninitialize COM
CoUninitialize();

// Clean up the GUI
cleanup_gui();

return (int)msg.wParam;
}