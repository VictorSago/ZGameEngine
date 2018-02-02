//
// Created by Victor Sago on 2018-01-10.
//

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <ZGE2d/MovingSprite.hpp>

#include "ZGE2d/GameEngine.hpp"
#include "ZGE2d/Session.hpp"
#include "ZGE2d/Label.hpp"
#include "ZGE2d/Sprite.hpp"

#define MAIN_FONT_LOCATION "../../zgeDemoApp/res/DejaVuSans.ttf"
#define PACMAN1_PATH "../../zgeDemoApp/res/Pacman-chomper.png"
#define PACMAN2_PATH "../../zgeDemoApp/res/Pacman-cropped.png"

using namespace std;

using namespace zge2d;

bool SessionQuitEvent(IEventHandler* obj, SDL_Event& e) {
    auto s = reinterpret_cast<Session*>(obj);
    if (e.type == SDL_QUIT) {
        cout << "Session caught an SDL_QUIT event\n";
    }
    s->stop();
    return true;
}

bool SessionKeyEvent(IEventHandler* obj, SDL_Event& e) {
    auto s = reinterpret_cast<Session*>(obj);
    bool handled = false;
    if (e.type == SDL_KEYDOWN) {
        unsigned int f;
        switch (e.key.keysym.sym) {
            case SDLK_PAGEUP:
                f = s->getMainTimer()->getFPS() + 5;
                std::cout << "Increasing FPS to " << f << std::endl;
                s->getMainTimer()->setFPS(f);
                handled = true;
                break;
            case SDLK_PAGEDOWN:
                f = s->getMainTimer()->getFPS() - 5;
                std::cout << "Decreasing FPS to " << f << std::endl;
                s->getMainTimer()->setFPS(f);
                handled = true;
                break;
            default:
                break;
        }
    }
    return handled;
}

bool LabelMouseEvent(IEventHandler* obj, SDL_Event& e){
    auto lbl = reinterpret_cast<Label*>(obj);
    bool handled = false;
    int mouseX, mouseY;
    if (e.type == SDL_MOUSEMOTION) {
        if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            if (mouseX >= lbl->getX() && mouseX <= lbl->getX() + lbl->getW()
                && mouseY >= lbl->getY() && mouseY <= lbl->getY() + lbl->getH()) {
                int newX = lbl->getX() + e.motion.xrel;
                int newY = lbl->getY() + e.motion.yrel;
                lbl->setXY(newX, newY);
                handled = true;
            }
        }
    }
    return handled;
}

bool SpriteMouseEvent(IEventHandler* obj, SDL_Event& e){
    auto spr = reinterpret_cast<Sprite*>(obj);
    bool handled = false;
    int mouseX, mouseY;
    if (e.type == SDL_MOUSEMOTION) {
        if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            if (mouseX >= spr->getX() && mouseX <= spr->getX() + spr->getW()
                && mouseY >= spr->getY() && mouseY <= spr->getY() + spr->getH()) {
                int newX = spr->getX() + e.motion.xrel;
                int newY = spr->getY() + e.motion.yrel;
                spr->setXY(newX, newY);
                handled = true;
            }
        }
    }
    return handled;
}

int main(int argc, char** argv) {
    cout << "Hello, My Game Engine!" << endl;
    cout << "SDL_Base_Path: " << SDL_GetBasePath() << endl;

    Session session;
#ifdef DEBUG_BUILD
    cout << "Main: Running in Debug mode: DEBUG symbol defined as " << DEBUG_BUILD << endl;
#endif

    GameWindow* window = session.newWindow("MainWindow", "Main Game Window");

    session.registerEventHandler(SDL_QUIT, &SessionQuitEvent);
    session.registerEventHandler(SDL_KEYDOWN, &SessionKeyEvent);

    Label* lbl1 = Label::getInstance(window->getRenderer(), 200, 100, "Some Text", MAIN_FONT_LOCATION, {0, 255, 255}, 36);
    Label* lbl2 = Label::getInstance(window->getRenderer(), 200, 150, "This is a Label!", MAIN_FONT_LOCATION, {255, 0, 255}, 24);
    lbl2->registerEventHandler(SDL_MOUSEMOTION, &LabelMouseEvent);
    window->addWidget(lbl1);
    window->addWidget(lbl2);
    SpriteGroup* sg1 = new SpriteGroup("Sprites");
    Sprite* sprite1 = new Sprite(window->getRenderer(), 300, 300, 32, 32, PACMAN1_PATH);
    Frames frames1r = {
            { 0, 0, 32, 32},
            { 32, 0, 32, 32}
    };
    Frames rot = {
            {0, 0, 32, 32},
            {0, 32, 32, 32},
            {0, 64, 32, 32},
            {0, 96, 32, 32}
    };
    sprite1->addAnimation(new Animation("right", frames1r));
    sprite1->addAnimation(new Animation("rotation", rot, 4));
    sprite1->registerEventHandler(SDL_MOUSEMOTION, &SpriteMouseEvent);
//    sprite1->setCurrentAnimation("rotation");
    MovingSprite* sprite2 = new MovingSprite(window->getRenderer(), 100, 350, 32, 32, PACMAN2_PATH, true);
    Frames frames3r = {
            { 0, 0, 32, 32},
            { 32, 0, 32, 32},
            { 64, 0, 32, 32},
            { 96, 0, 32, 32},
            { 128, 0, 32, 32},
            { 160, 0, 32, 32},
            { 192, 0, 32, 32},
            { 160, 0, 32, 32},
            { 128, 0, 32, 32},
            { 96, 0, 32, 32},
            { 64, 0, 32, 32},
            { 32, 0, 32, 32}
    };
    sprite2->addAnimation(new Animation("right", frames3r, 30));
    sprite2->setMoveDir(0, 0);
    sprite2->registerEventHandler(SDL_MOUSEMOTION, &SpriteMouseEvent);
    sg1->add(sprite1);
    sg1->add(sprite2);
    window->addSpriteGroup(sg1);
//    session.addElement(sprite1);
//    session.addElement(sprite2);
    cout << "Starting run().............\n";
    session.run();
    cout << "run() ended............\n";
//    delete sg1;

//    cout << "Label1 size: (" << lbl1->getW() << ", " << lbl1->getH() << ")" << endl;
//    cout << "Label2 size: (" << lbl2->getW() << ", " << lbl2->getH() << ")" << endl;

//    delete sprite2;
//    delete sprite1;
//    delete lbl2;
//    delete lbl1;

    return GameEngine::error_flags;
}
