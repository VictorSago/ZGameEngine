//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>
#include <utility>

#include "IEventHandler.hpp"
#include "Definitions.hpp"
#include "GameWindow.hpp"
#include "GameEngine.hpp"

namespace zge2d {


GameWindow::GameWindow(const std::string& winName, const std::string& winTitle, const std::string& bg_image,
                       SDL_Color bg_color, unsigned int w, unsigned int h) : name(winName), title(winTitle) {
    std::cout << "GameWindow " << winName << " (" << winTitle << ") constructor 6!" << std::endl;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (window != nullptr) {
        width = w;
        height = h;
        bgColor = bg_color;
        renderTarget = SDL_CreateRenderer(window, -1, RENDER_FLAGS);
        SDL_SetRenderDrawColor(renderTarget, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderClear(renderTarget);
        Texture* pTexture = Texture::loadTextureWithTransparency(renderTarget, bg_image, defaultTransparency);
        bgImage = std::shared_ptr<Texture>(pTexture);
        if (bgImage != nullptr) {
            background = true;
        } else {
            std::cerr << "Background Image Error." << std::endl;
            GameEngine::setErrorFlag(ERROR_BG_IMAGE);
            background = false;
        }
        widgets = new WidgetContainer();
        sprites = new SpriteContainer();
    } else {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
        GameEngine::setErrorFlag(ERROR_WIN_INIT);
    }
}

GameWindow::GameWindow(const std::string& winName, const std::string& winTitle,
                       SDL_Color bg_color, unsigned int w, unsigned int h) : name(winName), title(winTitle) {
    std::cout << "GameWindow " << winName << " (" << winTitle << ") constructor 5-1!" << std::endl;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (window != nullptr) {
        width = w;
        height = h;
        bgColor = bg_color;
        renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderTarget, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderClear(renderTarget);
        background = false;
        widgets = new WidgetContainer();
        sprites = new SpriteContainer();
    } else {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
        GameEngine::setErrorFlag(ERROR_WIN_INIT);
    }
}

GameWindow::GameWindow(const std::string& winTitle)
        : GameWindow(winTitle, winTitle, defaultWinBackground, defaultWinWidth, defaultWinHeight) {}

GameWindow::GameWindow(const std::string& winName, const std::string& winTitle, SDL_Color bg_color)
        : GameWindow(winName, winTitle, bg_color, defaultWinWidth, defaultWinHeight) {}

GameWindow::GameWindow(const std::string& winName, const std::string& winTitle, const std::string& bg_image)
        : GameWindow(winName, winTitle, bg_image, defaultWinBackground, defaultWinWidth, defaultWinHeight) {}

GameWindow::GameWindow(const std::string& winName, const std::string& winTitle, const std::string& bg_image,
                       unsigned int w, unsigned int h) : GameWindow(winName, winTitle, bg_image, defaultWinBackground, w, h) {}
/*
        : name(std::move(winName)), title(std::move(winTitle)) {
    std::cout << "GameWindow " << winName << " (" << winTitle << ") constructor 5-2!" << std::endl;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (window != nullptr) {
        width = w;
        height = h;
        renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderTarget, colorBlack.r, colorBlack.g, colorBlack.b, colorBlack.a);
        SDL_RenderClear(renderTarget);
//        SDL_RenderFillRect(renderTarget, NULL);
        Texture* pTexture = Texture::loadTextureWithTransparency(renderTarget, bg_image, defaultTransparency);
        bgImage = std::shared_ptr<Texture>(pTexture);
        if (bgImage != nullptr) {
            background = true;
        } else {
            std::cerr << "Background Image Error." << std::endl;
            GameEngine::setErrorFlag(ERROR_BG_IMAGE);
        }
    } else {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
        GameEngine::setErrorFlag(ERROR_WIN_INIT);
    }
    sprites = new SpriteContainer();
}
*/

zge2d::GameWindow::~GameWindow() {
    std::cout << "GameWindow " << title << " destructor!" << std::endl;
    if (renderTarget != nullptr) {
        SDL_DestroyRenderer(renderTarget);
        std::cout << "renderTarget destroyed." << std::endl;
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        std::cout << "window " << name << " destroyed." << std::endl;
    }
    delete sprites;
    delete widgets;
}

void zge2d::GameWindow::updateSprites() {
    sprites->update();
}

void zge2d::GameWindow::update() {
    SDL_RenderClear(renderTarget);
    if (background) {
        bgImage->draw(renderTarget, nullptr, nullptr);
//        SDL_RenderCopy(renderTarget, bgImage, NULL, NULL);
    } else {
        SDL_SetRenderDrawColor(renderTarget, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderFillRect(renderTarget, nullptr);
    }
    sprites->draw(renderTarget);
    widgets->draw(renderTarget);
}

void zge2d::GameWindow::draw() {
    SDL_RenderPresent(renderTarget);
}

bool GameWindow::handleEvent(SDL_Event& event) {
    bool handled = false;
    switch (event.type) {
        case SDL_WINDOWEVENT:
            handled = onWindowEvent(event);
            break;
        default:
            break;
    }
    if (!handled) {
        handled = widgets->delegateEvent(event);
    }
    if (!handled) {
        handled = handled || sprites->delegateEvent(event);
    }
    return handled;
}

bool GameWindow::onWindowEvent(SDL_Event& event) {
    return false;
}

}
