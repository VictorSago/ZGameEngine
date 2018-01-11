//
// Created by Victor Sago on 2018-01-10.
//

#include <iostream>
#include <SDL2/SDL.h>

#include <ZGE2d/GameEngine.hpp>
#include <ZGE2d/Session.hpp>

using namespace std;

using namespace zge2d;

int main(int argc, char** argv) {
    cout << "Hello, My Game Engine!" << endl;
/*
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    } else {
        cout << "SDL Initialized successfully!" << endl;
    }
*/

    Session session;

    session.run();

    SDL_Quit();
    return EXIT_SUCCESS;
}
