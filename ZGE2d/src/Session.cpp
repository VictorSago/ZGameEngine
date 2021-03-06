//
// Created by Victor Sago on 2018-01-10.
//

#include <iostream>
#include <utility>
#include <SDL2/SDL.h>

#include "Session.hpp"

namespace zge2d {

Session::Session() {
    std::cout << "Session constructor" << std::endl;
}

Session::~Session() {
    std::cout << "Session destructor..." << std::endl;
    for (auto win : windows) {
        delete win.second;
    }
    windows.clear();
}

GameWindow* Session::newWindow(const std::string& winName, const std::string& winTitle,
                               const std::string& bg_image, SDL_Color bgColor, unsigned int w, unsigned int h) {
    auto win = new GameWindow(winName, winTitle, bg_image, bgColor, w, h);
    windows.insert(std::make_pair(win->getName(), win));
    currentWindow = win;
    return win;
}

GameWindow* Session::newWindow(const std::string& winName, const std::string& winTitle,
                               SDL_Color bgColor, unsigned int w, unsigned int h) {
    auto win = new GameWindow(winName, winTitle, bgColor, w, h);
    windows.insert(std::make_pair(win->getName(), win));
    currentWindow = win;
    return win;
}

GameWindow* Session::newWindow(const std::string& winName, const std::string& winTitle,
                   const std::string& bg_image, unsigned int w, unsigned int h) {
    return newWindow(winName, winTitle, bg_image, defaultWinBackground, w, h);
}

GameWindow* Session::newWindow(const std::string& winName, const std::string& winTitle) {
    return newWindow(winName, winTitle, defaultWinBackground, defaultWinWidth, defaultWinHeight);
}

GameWindow* Session::newWindow(const std::string& winTitle) {
    return newWindow(winTitle, winTitle, defaultWinBackground, defaultWinWidth, defaultWinHeight);
}

void Session::run() {
    if (currentWindow == nullptr) {
        return;
    }
    SDL_Event eve{};
    timer.start();
    while (!quit) {
        while (SDL_PollEvent(&eve)) {
            bool handled = handleEvent(eve);
            if (!handled) {
                handled = currentWindow->handleEvent(eve);
            }
        } // while event
//        keyState = SDL_GetKeyboardState(nullptr);
        currentWindow->updateSprites();
        currentWindow->update();
        timer.capFPS();
        currentWindow->draw();
    } // while !quit
}

/*
void Session::run() {
    if (currentWindow == nullptr) {
        return;
    }
    SDL_Event eve{};
    timer.start();
    while (!quit) {
        while (SDL_PollEvent(&eve)) {
            bool handled = handleEvent(eve);
            if (!handled) {
                handled = currentWindow->handleEvent(eve);
            }
            switch (eve.type) {
                case SDL_QUIT:
                    quit = true;
                    std::cout << "SDL_QUIT event caught. \n";
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    for (Widget* w : *currentWindow->getWidgetContainer()->getWidgets()) {
                        w->mouseDown(eve);
                    }
                    for (GroupMap sg : currentWindow->getSpriteContainer()->getGroups()) {
                        for (auto s : *(sg.second)->getSprites()) {
                            s->mouseDown(eve);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    for (Widget* w : *currentWindow->getWidgetContainer()->getWidgets()) {
                        w->mouseUp(eve);
                    }
                    for (auto sg : currentWindow->getSpriteContainer()->getGroups()) {
                        for (Sprite* s : sg) {
                            s->mouseUp(eve);
                        }
                    }
                    break;
                case SDL_KEYDOWN:
                    for (Entity* c : components) {
                        c->keyDown(eve);
                    }
                    break;
                case SDL_KEYUP:
                    for (Entity* c : components) {
                        c->keyUp(eve);
                    }
                    break;
                default:
                    break;
            } // Switch
        } // while event
        timer.capFPS();
        for (Entity* c : components) {
            c->update();
        }
        SDL_Renderer* renderTarget = currentWindow->getRenderer();
        SDL_RenderClear(renderTarget);
        for (Entity* c : components) {
            c->draw(renderTarget);
        }
        SDL_RenderPresent(renderTarget);

    } // while !quit
}
*/

void Session::stop() {
    quit = true;
}

bool Session::onQuit() {
    stop();
    return true;
}

}