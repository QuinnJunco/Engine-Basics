/**
 * Header file to contain all dependencies for my basic game engine.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <glad/glad.h>
#include <condition_variable>
#include <atomic>
#include <SDL3/SDL.h>
#include <string.h>
#include <SDL3_image/SDL_image.h>
#include <filesystem>


#ifndef ENGINE_H
#define ENGINE_H

/* CONSTANTS */

// constexpr: constant expressions - values are assigned at compile time instead of run time
constexpr int SCREEN_WIDTH {640};
constexpr int SCREEN_HEIGHT {480};
namespace FS = std::filesystem;

/* FORWARD DECLARATIONS */
class Texture; 
class HashTable; 

/* CLASS PROTOTYPE DECLARATIONS */

class Engine {
    public:

        /**
         * Returns the singleton instance of the engine, if it doesn't exist then it is initialized
         */
        static Engine& get_instance() {
            static Engine instance;
            return instance;
        }

        Engine(const Engine&) = delete; // deletes the copy constructor

        Engine& operator=(const Engine&) = delete; // deletes the reassignment operator

        /**
         * Loads media to the SDL window.
         * @return bool: False if any error occurs, otherwise true.
         */
        bool load_media();

        /**
         * Basic getter for window pointer
         */
        SDL_Window* get_window();

        /**
         * Basic getter for renderer pointer
         */
        SDL_Renderer* get_renderer();

        /**
         * Basic setter for the active texture
         */
        void set_active_texture(Texture* T);

        /**
         * Basic getter for active texture
         */
        Texture* get_active_texture();

        /**
         * Basic getter for the asset manager table
         */
        HashTable* get_table();

        /**
         * Frees the media and all memory associated with the window then shuts down SDL.
         */
        void clean();

        

    private:

        /**
         * Default constructor
         */
        Engine() {
            mWindow = {nullptr};
            mRenderer = {nullptr};
            aTexture = {nullptr};
            
            init();
        }

        // Main window object
        SDL_Window* mWindow {nullptr};     // note: nullptr is best practice in place of NULL

        // Renderer object to translate textures to the window
        SDL_Renderer* mRenderer {nullptr};
        
        // active texture element
        Texture* aTexture {nullptr};

        HashTable* AssetManager {nullptr};

        /**
         * Initializes SDL and creates the window.
         * @return bool: False if any error occurs, otherwise true.
         */
        bool init() {
            // initializes SDL video library (only initialize what is needed)
            bool success {true};
        
            if (!SDL_Init(SDL_INIT_VIDEO)) { 
                SDL_Log("Failed to initialize SDL. Error: %s\n", SDL_GetError());
                success = false;
                std::cerr << "Failed to initialize"<< std::endl;
            } else {
        
                if (!SDL_CreateWindowAndRenderer("main", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &mWindow, &mRenderer)) {
                    SDL_Log("Failed to create window or renderer. Error: %s\n", SDL_GetError());
                    std::cerr << "Failed to create window or renderer"<< std::endl;
                    success = false;
                }
        
            }
            return success;
        }
};

#endif