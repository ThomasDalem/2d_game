#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "Texture.hpp"
#include "utils/Vec.hpp"

namespace SDL {
    
    class Texture;

    class Renderer {
        public:
            Renderer();
            Renderer(SDL_Window *window);
            ~Renderer();
            SDL_Point pt;

            SDL_Renderer *getRenderer();

            void initRenderer(SDL_Window *window);
            int setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
            int clear();
            int copy(Texture &texture, const SDL_Rect *srcRect = NULL, const SDL_Rect *dstRect = NULL);
            int copyEx(Texture &texture,
                       Vec2i &center,
                       double angle = 0.0,
                       const SDL_Rect *srcRect = NULL,
                       const SDL_Rect *dstRect = NULL,
                       SDL_RendererFlip flip = SDL_FLIP_NONE
            );
            void present();

        private:
            SDL_Renderer *_renderer;
    };

}

#endif // RENDERER_HPP