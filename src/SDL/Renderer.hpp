#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "Texture.hpp"

namespace SDL {
    
    class Texture;

    class Renderer {
        public:
            Renderer();
            Renderer(SDL_Window *window);
            ~Renderer();

            SDL_Renderer *getRenderer();

            void initRenderer(SDL_Window *window);
            int setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
            int clear();
            int copy(Texture &texture, const SDL_Rect *sourceRect = NULL, const SDL_Rect *destRect = NULL);
            void present();

        private:
            SDL_Renderer *_renderer;
    };

}

#endif // RENDERER_HPP