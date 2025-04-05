#include <SDL3/SDL.h>
#include <glad/glad.h>

const int WIDTH {640};
const int HEIGHT {480};
SDL_Window* window {nullptr};

int main() {

    SDL_Init(SDL_INIT_VIDEO); // initializes SDL
    
    // updates necessary settings
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // creates the window
    if (window = SDL_CreateWindow("hello", WIDTH, HEIGHT, SDL_WINDOW_OPENGL); window == nullptr) {
        SDL_Log("Failed to create window: Error %s\n", SDL_GetError());
        return 1;
    }

    // creates an openGL context on the current thread
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, glcontext);

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress()))

}