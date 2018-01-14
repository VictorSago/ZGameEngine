//
// Created by Victor Sago on 2018-01-14.
//

#include "Definitions.hpp"
#include "GameWindow.hpp"

#include <iostream>


namespace zge2d {

GameWindow::GameWindow(std::string winTitle)
        : GameWindow(winTitle, winTitle, defaultWinBackground, defaultWinWidth, defaultWinHeight) {}

GameWindow::GameWindow(std::string winName, std::string winTitle, SDL_Color bgcolor)
        : GameWindow(std::move(winName), std::move(winTitle), bgcolor, defaultWinWidth, defaultWinHeight) {}

GameWindow::GameWindow(std::string winName, std::string winTitle, SDL_Color bgcolor, unsigned int w, unsigned int h)
        : name(std::move(winName)), title(std::move(winTitle)) {
    std::cout << "GameWindow " << winTitle << " constructor!" << std::endl;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (window != nullptr) {
        width = w;
        height = h;
        background = false;
        bgColor = bgcolor;
        renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderTarget, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderClear(renderTarget);
//        SDL_RenderFillRect(renderTarget, NULL);
    } else {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
//        GameUtils::setErrorFlag(ERROR_WIN_INIT);
    }
//    sprites = new SpriteContainer();
}

GameWindow::GameWindow(std::string winName, std::string winTitle, std::string bg_image)
        : GameWindow(std::move(winName), std::move(winTitle), std::move(bg_image), defaultWinWidth, defaultWinHeight) {}

GameWindow::GameWindow(std::string winName, std::string winTitle, std::string bg_image, unsigned int w, unsigned int h)
        : name(std::move(winName)), title(std::move(winTitle)) {
    std::cout << "GameWindow " << winName << " (" << winTitle << ") constructor!" << std::endl;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (window != nullptr) {
        width = w;
        height = h;
        renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderTarget, colorBlack.r, colorBlack.g, colorBlack.b, colorBlack.a);
        SDL_RenderClear(renderTarget);
//        SDL_RenderFillRect(renderTarget, NULL);
        bgImage = Texture::loadTextureWithTransparency(renderTarget, bg_image, defaultTransparency);
        if (bgImage != nullptr) {
            background = true;
        } else {
//            GameUtils::setErrorFlag(ERROR_BG_IMAGE);
        }
    } else {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
//        GameUtils::setErrorFlag(ERROR_WIN_INIT);
    }
//    sprites = new SpriteContainer();
}

zge2d::GameWindow::~GameWindow() {
    std::cout << "GameWindow " << title << " destructor!" << std::endl;
//    if (bgImage != nullptr) {
//        SDL_DestroyTexture(bgImage);
//        std::cout << "bgimage destroyed." << std::endl;
//    }
    if (renderTarget != nullptr) {
        SDL_DestroyRenderer(renderTarget);
        std::cout << "renderTarget destroyed." << std::endl;
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        std::cout << "window " << name << " destroyed." << std::endl;
    }
//    delete sprites;
}

void zge2d::GameWindow::updateSprites() {
//    sprites->update();
}

void zge2d::GameWindow::update() {
    SDL_RenderClear(renderTarget);
    if (background) {
        bgImage->draw(renderTarget, NULL, NULL);
//        SDL_RenderCopy(renderTarget, bgImage, NULL, NULL);
    } else {
        SDL_SetRenderDrawColor(renderTarget, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderFillRect(renderTarget, NULL);
    }
//    sprites->draw(renderTarget);
}

void zge2d::GameWindow::draw() {
    SDL_RenderPresent(renderTarget);
}

}
