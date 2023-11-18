#include <iostream>
#include "Texture.hpp"
#include "Surface.hpp"

using namespace SDL;

Texture::Texture(const std::string &path, Renderer &renderer) : _isLoaded(false)
{
    Surface surface(path);

    if (!surface.isLoaded()) {
        std::cout << "Error: texture not loaded because surface is not loaded" << std::endl;
        return;
    }
    _texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (_texture == NULL) {
        std::cout << "Error: could not create texture : " << SDL_GetError() << std::endl;
        return;
    }
    _isLoaded = true;
}

Texture::~Texture()
{
    if (_texture) {
        SDL_DestroyTexture(_texture);
    }
}

SDL_Texture *Texture::getTexture()
{
    return _texture;
}

bool Texture::isLoaded() const
{
    return _isLoaded;
}
