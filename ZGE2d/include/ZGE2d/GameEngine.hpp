//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_SYSTEM_HPP
#define ZGE2D_SYSTEM_HPP

#include <SDL2/SDL.h>

namespace zge2d {

class GameEngine {
    protected:
        static GameEngine engineInstance;
    private:
//        SDL_Window* window;
//        SDL_Renderer* renderer;
    protected:
        /** \brief Field for storing a pointer to KeyStates
         *  These key states are read outside the event loop
         *  and are then used to control sprites
         */
        const Uint8 *keyState;
    protected:
        /**< Initialization of SDL before the main program starts */
        static void initSDL();
    public:
        virtual ~GameEngine();

        static GameEngine* getInstance() {return &engineInstance;}
//        SDL_Renderer* getRenderer() const;
//        SDL_Window* getWindow() const;

        const Uint8* getKeyState() { return keyState; }

    private:
        /**< Prevent creation of objects of this class */
        GameEngine();

    public:
        /**< Prevent copying of objects of this class */
        GameEngine(const GameEngine&) = delete;
        const GameEngine& operator=(const GameEngine&) = delete;
    public:
        static int error_flags;
        static void setErrorFlag(int error) { error_flags = error_flags | error; }
        static void resetErrorFlags() { error_flags = 0; }
};

//extern GameEngine engineInstance;

}

#endif //ZGE2D_SYSTEM_HPP
