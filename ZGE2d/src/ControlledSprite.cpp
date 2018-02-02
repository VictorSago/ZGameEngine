//
// Created by Victor Sago on 2018-01-14.
//

#include <sstream>
#include "ControlledSprite.hpp"

namespace zge2d {

ControlledSprite::ControlledSprite(SDL_Renderer* renderTarget, int x, int y, int w, int h, std::string filePath, bool visibility)
                    : MovingSprite(renderTarget, x, y, w, h, filePath, visibility) { }

ControlledSprite::~ControlledSprite() {
    std::cout << "ControlledSprite destructor." << std::endl;
    controls.clear();
}

/*
void ControlledSprite::setControls(SDL_Scancode* keys, int num) {
    controls.clear();
    for (int i = 0; i < num; i++) {
        controls.push_back(keys[i]);
    }
}
*/

void ControlledSprite::update() {
    const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
//    handleControls(keyStates);
    if(collisionHandler) {
        handleCollisions();
    }
    move();
    animate();
//    std::cout << "CropRect: {" << cropRect.x << ", " << cropRect.y << ", " << cropRect.w << ", " << cropRect.h << "}\n";
//    std::cout << "BoundingRect: {" << boundingRect.x << ", " << boundingRect.y << ", " << boundingRect.w << ", " << boundingRect.h << "}\n";
}

//void ControlledSprite::update(float deltaTime, bool active) {
////    std::cout << "\t\tControlledSprite: update()" << std::endl;
//    if (!alwaysActive) {
//        isActive = active;
//    }
////    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
////    handleControls(keyState);
//    handleControls(GameEngine::getInstance()->getKeyState());
//    changePosition(deltaTime);
//    if (isActive) {
//        animate(deltaTime);
//    } else {
//        frameCounter = 0;
//        cropRect.x = cropRect.w;
//    }
//}

//void ControlledSprite::update(float deltaTime) {
//    update(deltaTime, true);
//}

#ifdef DEBUG_BUILD
std::string ControlledSprite::toString() {
    std::stringstream ss;
    ss << MovingSprite::toString();
    ss << "controls: ";
    for (auto c : controls) {
        ss << c << " ";
    }
    return ss.str();
}
#endif

} // namespace
