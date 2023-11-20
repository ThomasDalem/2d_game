#ifndef TEXTURESLOADER_HPP
#define TEXTURESLOADER_HPP

#include <unordered_map>
#include <string>
#include <memory>
#include "SDL/Texture.hpp"

class TexturesLoader {
public:
    TexturesLoader(SDL::Renderer &renderer);
    ~TexturesLoader();

    SDL::Texture &getTexture(const std::string &path);

private:
    std::unordered_map<std::string, SDL::Texture> _textures;
    SDL::Renderer &_renderer;
};

#endif // TEXTURESLOADER_HPP