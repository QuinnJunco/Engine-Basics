#include <iostream>
#include <string.h>
#include <SDL3_image/SDL_image.h>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
    public:

    /**
     * Texture constructor
     */
    Texture();

    /**
     * Texture destructor
     */
    ~Texture();

    /**
     * Frees associated memory
     */
    void clean();

    /**
     * Loads the texture from disk
     */
    bool load_texture(std::string path);

    /**
     * Draws the texture to the screen surface at a specified position
     */
    void render(float x, float y);

    /**
     * Simple getter for texture width
     */
    int get_width();

    /**
     * Simple getter for texture height
     */
    int get_height();

    
    private:

        SDL_Texture* texture; // Texture object

        int width; // Texture width
        int height; // Texture height

};
#endif