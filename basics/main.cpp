#include "engine.h"
#include "texture.h"
#include "hashtable.h"

void update_color(SDL_Color &b) {
    const bool* keyStates = SDL_GetKeyboardState(nullptr);

    if (keyStates[SDL_SCANCODE_UP]) { // red
        b.b = 0x00;
        b.g = 0x00;
    } else if (keyStates[SDL_SCANCODE_DOWN]) { // blue
        b.r = 0x00;
        b.g = 0x00;
    } else if (keyStates[SDL_SCANCODE_LEFT]) { // brown ?
        b.r = 0x00;
    } else if (keyStates[SDL_SCANCODE_RIGHT]) { // purple
        b.g = 0x00;
    }
}

int main()
{
    int status {0};


    if (Engine& E = Engine::get_instance(); E.get_window() == nullptr) { // initializes SDL 
        status = 1;
    } else if (!E.load_media()) { // loads media
        status = 2;
    } else {
        
        bool quit {false};
        HashTable* asset_table = E.get_table();

        Texture* uTexture = static_cast<Texture*>(asset_table->find("./assets/up_arrow.png"));
        Texture* dTexture = static_cast<Texture*>(asset_table->find("./assets/down_arrow.png"));
        Texture* lTexture = static_cast<Texture*>(asset_table->find("./assets/left_arrow.png"));
        Texture* rTexture = static_cast<Texture*>(asset_table->find("./assets/right_arrow.png"));

        SDL_Event event;
        SDL_zero(event);

        while (!quit) {
            SDL_PollEvent(&event);
            if (event.type == SDL_EVENT_QUIT) {
                quit = {true};
                std::cout << "Quit" << std::endl;
            } 
            
            else if (event.type == SDL_EVENT_KEY_DOWN) {

                switch (event.key.key)
                {
                case SDLK_UP:
                    E.set_active_texture(uTexture);
                    break;
                case SDLK_LEFT:
                    E.set_active_texture(lTexture);
                    break;
                case SDLK_DOWN:
                    E.set_active_texture(dTexture);
                    break;
                case SDLK_RIGHT:
                    E.set_active_texture(rTexture);
                    break;
                default:
                    break;
                }

            }

            SDL_Color bColor = {0xff, 0xff, 0xff, 0xff};

            update_color(bColor);

            // fills the renderer with the background color
            SDL_SetRenderDrawColor(E.get_renderer(), bColor.r, bColor.g, bColor.b, bColor.a);
            SDL_RenderClear(E.get_renderer());

            E.get_active_texture()->render((SCREEN_WIDTH - E.get_active_texture()->get_width())*0.5f,
            (SCREEN_HEIGHT - E.get_active_texture()->get_height())*0.5f); // renders the texture
            
            SDL_RenderPresent(E.get_renderer()); // updates the screen
        }

        if (Engine& E = Engine::get_instance(); E.get_window() != nullptr) {
            E.clean();
        }

    }
    
    std::cerr << status << std::endl;
    return status;
}
