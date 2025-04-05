#include "engine.h" 
#include "texture.h"
#include "hashtable.h"

bool Engine::load_media() {
    AssetManager = new HashTable(50);
    bool success {true};
    
    if (!success || !AssetManager->insert("./assets/left_arrow.png")) {
        SDL_Log("Failed to load texture from path. Error: %s\n");
        success = {false};
    } else {
        set_active_texture(static_cast<Texture*>(AssetManager->find("./assets/left_arrow.png")));
    }

    if (!success || !AssetManager->insert("./assets/right_arrow.png")) {
        SDL_Log("Failed to load texture from path. Error: %s\n", SDL_GetError());
        success = {false};
    }

    if (!success || !AssetManager->insert("./assets/up_arrow.png")) {
        SDL_Log("Failed to load texture from path. Error: %s\n", SDL_GetError());
        success = {false};
    }

    if (!success || !AssetManager->insert("./assets/down_arrow.png")) {
        SDL_Log("Failed to load texture from path. Error: %s\n", SDL_GetError());
        success = {false};
    }

    return success;
}

SDL_Window* Engine::get_window() {
    return mWindow;
}

SDL_Renderer* Engine::get_renderer() {
    return mRenderer;
}

HashTable* Engine::get_table() {
    return AssetManager;
}

void Engine::set_active_texture(Texture* T) {
    aTexture = T;
}

Texture* Engine::get_active_texture() {
    return aTexture;
}
        
void Engine::clean() {
    SDL_Log("Cleaning Up...\n");

    aTexture = nullptr;

    AssetManager->clean();

    SDL_DestroyRenderer(mRenderer);
    mRenderer = nullptr;

    SDL_DestroyWindow(mWindow); // frees the window
    mWindow = nullptr;

    SDL_Log("Cleaning complete, closing SDL.\n");
    SDL_Quit(); // quits out of the subsystem
}

