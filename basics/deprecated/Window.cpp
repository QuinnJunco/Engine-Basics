#include "window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            
        }
        return 0;

        case WM_CLOSE: { // posted when a window is closed
            DestroyWindow(hwnd);
        }
            return 0;;

        case WM_DESTROY: {// posted when a window is destroyed
            PostQuitMessage(0);
        }
            return 0;

    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void Window::init(const std::string& title, int width, int height) {

    m_hInstance = GetModuleHandleA(nullptr); // I don't know

    // registers the window class
    const char* CLASS_NAME = "Sample Window Class";

    WNDCLASS wClass = {};
    wClass.hInstance = m_hInstance;
    wClass.lpfnWndProc = WindowProc;
    wClass.lpszClassName = CLASS_NAME;
    // wClass.hIcon used to give the window an icon

    RegisterClass(&wClass);

    RECT rect {};
    rect.top = 250;
    rect.left = 250;
    rect.right = rect.left+width;
    rect.bottom = rect.top+height;

    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // adjusts the window so the canvas is the size of the rect not the border

    // creates the window
    m_hwnd = CreateWindowEx(
        0, // optional window styles
        CLASS_NAME, // class name
        title.c_str(), // window title
        WS_OVERLAPPEDWINDOW, // window style LOOK INTO THIS

        // dimensions and position
        rect.left,
        rect.top,
        rect.right - rect.left, // uses the corrected width
        rect.bottom - rect.top, // uses the corrected height

        nullptr, // parent window
        nullptr, // menu 
        m_hInstance, // Instance handle
        nullptr // additional application data
    );

    if (m_hwnd == nullptr) {
        std::cerr << "Failed to create window." << std::endl;
        return;
    }

    ShowWindow(m_hwnd, SW_SHOW);

    m_hdc = GetDC(m_hwnd); // grab device context

    // prepares pixel format
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

    // sets up pixel format
    int pixelFormat = ChoosePixelFormat(m_hdc, &pfd);
    SetPixelFormat(m_hdc, pixelFormat, &pfd);

    // create openGL rendering context
    if (m_hglrc = wglCreateContext(m_hdc); !m_hglrc) {
        std::cerr << "Failed to create rendering context" << std::endl;
        return;
    }

    // makes the rendering context the current context
    if (!wglMakeCurrent(m_hdc, m_hglrc)) {
        std::cerr << "Failed to make context current" << std::endl;
        return;
    }

    // initializes glad
    if (!gladLoadGLLoader((GLADloadproc)wglGetProcAddress)) {
        std::cerr << "Failed to initialize glad" << std::endl;
        std::cerr << glGetString(GL_VERSION) << std::endl;
        return;
    }
    

    glViewport(0, 0, width, height); // sets the viewport stuff
}


Window::Window(const std::string& title) {
    init(title, 640, 480);
}

Window::Window(const std::string& title, const int w, const int h) {
    init(title, w, h);
}

Window::~Window() {
    UnregisterClass((LPCSTR)m_CLASS_NAME, m_hInstance);

    // releases the device context
    ReleaseDC(m_hwnd, m_hdc);
}

bool Window::swap_buffers() {
    std::cout << "Swapping buffers" << std::endl;
    return true;
}

bool Window::process_messages() {

    MSG msg = {};

    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
        if (msg.message == WM_QUIT) { // return false because want it to end when a quit message is received
            return false;
        }

        TranslateMessage(&msg); // translates messages into keystrokes LOOK INTO
        DispatchMessage(&msg); // sends message to the windowproc
    }

    return true;
}

void Window::resize(UINT flag, int width, int height) {
    // TODO: implement
}


