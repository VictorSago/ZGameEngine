//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_SYSTEM_HPP
#define ZGE2D_SYSTEM_HPP

#include <SDL2/SDL.h>

namespace zge2d {

class GameEngine {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    protected:
        static void initSDL();
    public:
        GameEngine();
        virtual ~GameEngine();

        SDL_Renderer* getRenderer() const;
        SDL_Window* getSdlWindow() const;
};

extern GameEngine gameEngine;

}

#endif //ZGE2D_SYSTEM_HPP
