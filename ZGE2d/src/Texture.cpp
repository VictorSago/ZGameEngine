//
// Created by Victor Sago on 2018-01-11.
//

#include <iostream>
#ifdef DEBUG_BUILD
    #include <sstream>
#endif

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GameEngine.hpp"
#include "Texture.hpp"

namespace zge2d {


Texture::Texture(SDL_Texture* sdlTexture) : texture(sdlTexture) {
}

Texture::~Texture() {
    if (texture != nullptr) {
        std::cout << "Texture destructor. " << width << ", " << height << std::endl;
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

Texture* Texture::loadTexture(SDL_Renderer* renderTarget, std::string filePath) {
    SDL_Texture* texture = nullptr;
    Texture* ret = nullptr;
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if(surface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderTarget, surface);
        if (texture == nullptr) {
            std::cerr << "Error converting surface to texture: " << SDL_GetError() << std::endl;
        }
        ret = new Texture(texture);
        ret->setDimensions(surface->w, surface->h);
        SDL_FreeSurface(surface);
    } else {
        std::cerr << "Image loading error in LoadTexture(): " << filePath << ":_:" << SDL_GetError() << std::endl;
    }
    return ret;
}

Texture* Texture::loadTextureWithTransparency(SDL_Renderer* renderTarget, std::string filePath, SDL_Color transp) {
    SDL_Texture* texture = nullptr;
    Texture* ret = nullptr;
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if(surface != nullptr) {
        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, transp.r, transp.g, transp.b));
        texture = SDL_CreateTextureFromSurface(renderTarget, surface);
        if (texture == nullptr) {
            std::cerr << "Error converting surface to texture: " << SDL_GetError() << std::endl;
        }
        ret = new Texture(texture);
        ret->setDimensions(surface->w, surface->h);
        SDL_FreeSurface(surface);
    } else {
        std::cerr << "Image loading error in LoadTextureWithTransparency(): " << filePath << ":_:" << SDL_GetError() << std::endl;
    }
    return ret;
}

Texture *Texture::makeFromText(SDL_Renderer* renderTarget, std::string fontPath, std::string text, SDL_Color fgColor, int txtSize) {
    SDL_Texture* texture = nullptr;
    Texture* ret = nullptr;
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), txtSize);
    if (font == nullptr) {
        std::cerr << "Error loading font: " << fontPath << ":_:" << TTF_GetError() << std::endl;
        return nullptr;
    }
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fgColor);
    if (surface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderTarget, surface);
        if (texture == nullptr) {
            std::cerr << "Error converting text surface to texture: " << SDL_GetError() << std::endl;
        }
        ret = new Texture(texture);
        ret->setDimensions(surface->w, surface->h);
        SDL_FreeSurface(surface);
    } else {
        std::cerr << "Error rendering text to a surface: " << text << ", " << txtSize
                  << "\nFrom font: " << fontPath << "\n:_:" << TTF_GetError() << std::endl;
    }
    TTF_CloseFont(font);
    return ret;
}

void Texture::draw(SDL_Renderer* renderTarget, const SDL_Rect* srcRect, const SDL_Rect* dstRect,
                   double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(renderTarget, texture, srcRect, dstRect, angle, center, flip);
}

#ifdef DEBUG_BUILD
std::string Texture::toString() {
    std::string sep (", ");
    std::stringstream ss;
    ss << "Texture: dims: {" << width << sep << height << "} ";
    ss << "SDL_Texture ptr: " << texture << "\n";
    return ss.str();
}
#endif

}
