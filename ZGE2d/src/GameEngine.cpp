//
// Created by Victor Sago on 2018-01-10.
//

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GameEngine.hpp"

namespace zge2d {

GameEngine GameEngine::gameEngine;

GameEngine::GameEngine() {
    std::cout << "GameEngine constructor: Entering." << std::endl;
#ifdef DEBUG_BUILD
    std::cout << "GameEngine: Running in Debug mode: DEBUG symbol defined as" << DEBUG_BUILD << std::endl;
#endif
    initSDL();
    window = SDL_CreateWindow("Default Game Engine Window",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
    if (window != nullptr) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_RenderClear(renderer);
    } else {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
    }
    std::cout << "GameEngine GameEngine constructor: Leaving." << std::endl;
}

zge2d::GameEngine::~GameEngine() {
    std::cout << "GameEngine GameEngine destructor: Entering" << std::endl;
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        std::cout << "renderTarget destroyed." << std::endl;
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        std::cout << "window " << "\'Default Game Engine Window\'" << " destroyed." << std::endl;
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    std::cout << "All SDL quit." << std::endl;
}

void GameEngine::initSDL() {
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL Init error: " << SDL_GetError() << std::endl;
//        GameUtils::setErrorFlag(ERROR_SDL_INIT);
    }
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
//        SDL_Quit();
//        GameUtils::setErrorFlag(ERROR_IMG_INIT);
    }
    if(TTF_Init() < 0) {
        std::cerr << "TTF_Init exception: " << SDL_GetError() << std::endl;
//        GameUtils::setErrorFlag(ERROR_TTF_INIT);
//        IMG_Quit();
//        SDL_Quit();
    }
}

SDL_Renderer* GameEngine::getRenderer() const {
    return renderer;
}

SDL_Window* GameEngine::getWindow() const {
    return window;
}

}
