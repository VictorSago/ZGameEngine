//
// Created by Victor Sago on 2018-01-10.
//

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello, My Game Engine!" << endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    } else {
        cout << "SDL Initialized successfully!" << endl;
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}
