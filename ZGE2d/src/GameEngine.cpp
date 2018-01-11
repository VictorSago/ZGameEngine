//
// Created by Victor Sago on 2018-01-10.
//

#include <iostream>
#include "GameEngine.hpp"

namespace zge2d {

zge2d::GameEngine::GameEngine() {
    std::cout << "GameEngine constructor: Entering." << std::endl;
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
    SDL_Quit();
    std::cout << "All SDL quit." << std::endl;
}

void GameEngine::initSDL() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL Init error: " << SDL_GetError() << std::endl;
//        GameUtils::setErrorFlag(ERROR_SDL_INIT);
    }
}

SDL_Renderer* GameEngine::getRenderer() const {
    return renderer;
}

SDL_Window* GameEngine::getSdlWindow() const {
    return window;
}

GameEngine gameEngine;

}
