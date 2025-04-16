#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <string>
#include <windows.h>
#include "../libraries/GLAD/include/glad/glad.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
    public:
        enum Mode {
            WINDOWED = 0,
            MINIMIZED,
            MAXIMIZED,
            FULLSCREEN
        };

        /**
         * Default constructor, automatically 640x480
         * @param title: Title of the window
         */
        Window(const std::string& title);

        /**
         * Sized constructor
         * @param title: Title of the window
         * @param w: Desired window width
         * @param h: Desired window height
         */
        Window(const std::string& title, const int w, const int h);

        // deletes the copy constructor
        Window(const Window&) = delete;

        /**
         * Default destructor
         */
        ~Window();

        /**
         * Swaps openGL buffers idk man
         * @returns bool
         */
        bool swap_buffers();
    
        /**
         * Processes all messages for the window
         * @returns bool
         */
        bool process_messages();
        
    private:
        
        int m_width {0};
        int m_height {0};

        HWND m_hwnd {nullptr};
        HINSTANCE m_hInstance {nullptr};
        HDC m_hdc {nullptr};
        HGLRC m_hglrc {nullptr};
        const wchar_t* m_CLASS_NAME {nullptr};

        void init(const std::string& title, int width, int height); 

        /**
         * Static function to handle WM_SIZE messages
         * @param flag: additional information from the OS shows whether window was minimized, maximized, or resized
         * @param width: new width
         * @param height: new height
         */
        static void resize(UINT flag, int width, int height);

};


#endif