//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_SYSTEM_HPP
#define ZGE2D_SYSTEM_HPP

#include <SDL2/SDL.h>

namespace zge2d {

class GameEngine {
    protected:
        static GameEngine gameEngine;
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    protected:
        const Uint8 *keyState;
    protected:
        static void initSDL();
    public:
        virtual ~GameEngine();

        static GameEngine* getInstance() {return &gameEngine;}
        SDL_Renderer* getRenderer() const;
        SDL_Window* getWindow() const;

        const Uint8* getKeyState() { return keyState; }

    protected:
        GameEngine();
};

//extern GameEngine gameEngine;

}

#endif //ZGE2D_SYSTEM_HPP
