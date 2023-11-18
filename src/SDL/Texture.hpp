#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <SDL2/SDL.h>
#include "Renderer.hpp"

namespace SDL {

    class Renderer;

    class Texture {
    public:
        Texture(const std::string &path, Renderer &renderer);
        ~Texture();

        SDL_Texture *getTexture();
        bool isLoaded() const;

    private:
        SDL_Texture *_texture;
        bool _isLoaded;
    };
    
}

#endif // TEXTURE_HPP