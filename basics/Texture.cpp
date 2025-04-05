#include "texture.h"
#include "engine.h"

Texture::Texture() {
    texture = {nullptr};
    width = {0};
    height = {0};
}

Texture::~Texture() {
    clean();
}

bool Texture::load_texture(std::string path) {
    clean(); // remove any existing texture

    std::cerr << "Loading texture" << std::endl;
    if (Engine& E = Engine::get_instance(); E.get_window() != nullptr) {
        // loads the image at the end of the path as a surface to be loaded as a texture
        if (SDL_Surface* surface = IMG_Load(path.c_str()); surface == nullptr) {
            SDL_Log("Failed to load image via path. Error: %s\n", SDL_GetError());
        } else {

            // loads SDL_Texture object into wrapper to be manipulated here
            if (texture = SDL_CreateTextureFromSurface(E.get_renderer(), surface); texture == nullptr) {
                SDL_Log("Failed to create texture from image surface. Error %s\n", SDL_GetError());
            } else {
                // extracts the dimensions from the SDL_Texture object
                width = texture->w;
                height = texture->h;
            }

            // frees surface object because it is no longer useful
            SDL_DestroySurface(surface);
        }
    }
    return texture != nullptr;
}

void Texture::render(float x, float y) {
    Engine& E = Engine::get_instance(); // accesses the engine singleton

    // creates a rectangle for placing the texture into the window
    SDL_FRect destination_rect = {x, y, static_cast<float>(width), static_cast<float>(height)}; // static casting avoids type conversion issues

    // renders the texture into the destination rectangle
    SDL_RenderTexture(E.get_renderer(), texture, nullptr, &destination_rect);
}

int Texture::get_height() {
    return height;
}

int Texture::get_width() {
    return width;
}

void Texture::clean() {
    // frees everything up
    SDL_DestroyTexture(texture);
    texture = nullptr;
    width = 0;
    height = 0;
}
