#include "TexturesLoader.hpp"

TexturesLoader::TexturesLoader(SDL::Renderer &renderer) : _renderer(renderer), _test("../assets/tree.png", _renderer)
{}

TexturesLoader::~TexturesLoader()
{}

SDL::Texture &TexturesLoader::getTexture(const std::string &path)
{
    auto it = _textures.try_emplace("path", path, _renderer).first;

    return it->second;
}
