//
// Created by Victor Sago on 2018-01-11.
//

#ifndef ZGE2D_TEXTURE_HPP
#define ZGE2D_TEXTURE_HPP

#include <SDL2/SDL.h>

namespace zge2d {

class Texture {
    private:
        SDL_Texture* texture;
    public:
        Texture(SDL_Texture *texture);

        virtual ~Texture();
};

}

#endif //ZGE2D_TEXTURE_HPP
