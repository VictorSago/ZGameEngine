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

int main(int argc, char** argv) {
    cout << "Hello, My Game Engine!" << endl;
    cout << "SDL_Base_Path: " << SDL_GetBasePath() << endl;

    Session session;
#ifdef DEBUG_BUILD
    cout << "Main: Running in Debug mode: DEBUG symbol defined as " << DEBUG_BUILD << endl;
#endif

    GameWindow* window = session.newWindow("MainWindow", "Main Game Window");
//    SpriteGroup* widgets = new SpriteGroup("Widgets");
    Label* lbl1 = Label::getInstance(window->getRenderer(), 200, 100, "Some Text", MAIN_FONT_LOCATION, {0, 255, 255}, 36);
    Label* lbl2 = Label::getInstance(window->getRenderer(), 200, 150, "This is a Label!", MAIN_FONT_LOCATION, {255, 0, 255}, 24);
    window->addWidget(lbl1);
    window->addWidget(lbl2);
//    widgets->add(lbl1);
//    widgets->add(lbl2);
//    session.addElement(lbl1);
//    session.addElement(lbl2);
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
    sg1->add(sprite1);
    sg1->add(sprite2);
    window->addSpriteGroup(sg1);
//    session.addElement(sprite1);
//    session.addElement(sprite2);
    cout << "Starting run().............\n";
    session.run();
    cout << "run() ended............\n";

//    cout << "Label1 size: (" << lbl1->getW() << ", " << lbl1->getH() << ")" << endl;
//    cout << "Label2 size: (" << lbl2->getW() << ", " << lbl2->getH() << ")" << endl;

//    delete sprite2;
//    delete sprite1;
//    delete lbl2;
//    delete lbl1;

    return GameEngine::error_flags;
}
