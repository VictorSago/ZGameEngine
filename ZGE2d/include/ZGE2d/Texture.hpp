//
// Created by Victor Sago on 2018-01-11.
//

#ifndef ZGE2D_TEXTURE_HPP
#define ZGE2D_TEXTURE_HPP

#include <string>

#include <SDL2/SDL.h>


namespace zge2d {

class Texture {
    public:
        static Texture* loadTexture(SDL_Renderer* renderTarget, std::string filePath);
        static Texture* loadTextureWithTransparency(SDL_Renderer* renderTarget, std::string filePath, SDL_Color transp);
        static Texture* makeFromText(SDL_Renderer* renderTarget, std::string fontPath,
                                     std::string text, SDL_Color fgColor, int txtSize = 16);
    protected:
        int width = 0;
        int height = 0;
        SDL_Texture* texture;

    public:
        virtual ~Texture();

        int getWidth() const { return width; }
        int getHeight() const { return height; }

        void draw(SDL_Renderer* renderTarget, const SDL_Rect* srcRect, const SDL_Rect* dstRect,
                  double angle = 0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

    protected:
        Texture() = default;
        explicit Texture(SDL_Texture *texture);

    protected:
        void setDimensions(int w, int h) { width = w; height = h; }

#ifdef DEBUG_BUILD
    public:
        std::string toString();
#endif
};

}

#endif //ZGE2D_TEXTURE_HPP
