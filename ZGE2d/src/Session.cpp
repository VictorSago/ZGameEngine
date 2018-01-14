//
// Created by Victor Sago on 2018-01-10.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "GameEngine.hpp"
#include "Session.hpp"

namespace zge2d {

Session::~Session() {
    components.clear();
    std::cout << "Session destructor..." << std::endl;
}

void Session::addElement(VisComp *comp) {
    components.push_back(comp);
}

void Session::run() {
    GameEngine* engine = GameEngine::getInstance();
    SDL_Event eve{};
    timer.start();
    while (!quit) {
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT:
                    quit = true;
                    std::cout << "SDL_QUIT event caught. \n";
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    for (VisComp* c : components) {
                        c->mouseDown(eve);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    for (VisComp* c : components) {
                        c->mouseUp(eve);
                    }
                    break;
                case SDL_KEYDOWN:
                    for (VisComp* c : components) {
                        c->keyDown(eve);
                    }
                    break;
                case SDL_KEYUP:
                    for (VisComp* c : components) {
                        c->keyUp(eve);
                    }
                    break;
                default:
                    break;
            } // Switch
        } // while event
        timer.capFPS();
        for (VisComp* c : components) {
            c->update();
        }
        SDL_RenderClear(engine->getRenderer());
        for (VisComp* c : components) {
            c->draw();
        }
        SDL_RenderPresent(engine->getRenderer());

    } // while !quit
}

void Session::stop() {
    quit = true;
}

}