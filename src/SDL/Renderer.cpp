#include <iostream>
#include "Renderer.hpp"

using namespace SDL;

Renderer::Renderer() : _renderer(NULL)
{

}

Renderer::Renderer(SDL_Window *window)
{
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (_renderer == NULL)
    {
        std::cout << "Error while creating renderer : " <<  SDL_GetError() << std::endl;
        throw "Renderer error";
    };
}

Renderer::~Renderer()
{
    if (_renderer) {
        SDL_DestroyRenderer(_renderer);
    }
}

SDL_Renderer *Renderer::getRenderer()
{
    return _renderer;
}

void Renderer::initRenderer(SDL_Window *window)
{
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (_renderer == NULL)
    {
        std::cout << "Error while creating renderer : " <<  SDL_GetError() << std::endl;
        throw "Renderer error";
    };
}

int Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

int Renderer::clear()
{
    return SDL_RenderClear(_renderer);
}

int Renderer::copy(Texture &texture, const SDL_Rect *sourceRect, const SDL_Rect *destRect)
{
    return SDL_RenderCopy(_renderer, texture.getTexture(), sourceRect, destRect);
}

void Renderer::present()
{
    return SDL_RenderPresent(_renderer);
}