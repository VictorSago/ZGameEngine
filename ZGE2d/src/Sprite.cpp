//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>
#ifdef DEBUG_BUILD
    #include <sstream>
#endif

#include "GameEngine.hpp"
#include "Sprite.hpp"
#include "Definitions.hpp"

namespace zge2d {


Sprite::Sprite(int x, int y, int w, int h, std::string imagePath, bool visibility) : VisComp(x, y, w, h, visibility) {
    Texture* pTexture = Texture::loadTexture(GameEngine::getInstance()->getRenderer(), std::move(imagePath));
    texture = std::shared_ptr<Texture>(pTexture);
    cropRect.x = cropRect.y = 0;
    cropRect.w = w;
    cropRect.h = h;
    collisionHandler = false;
}

Sprite::Sprite(const SDL_Rect &r, std::string imagePath, bool visibility) : VisComp(r, visibility) {
    Texture* pTexture = Texture::loadTexture(GameEngine::getInstance()->getRenderer(), std::move(imagePath));
    texture = std::shared_ptr<Texture>(pTexture);
    cropRect.x = cropRect.y = 0;
    cropRect.w = r.w;
    cropRect.h = r.h;
}

Sprite::~Sprite() {
    std::cout << "Sprite destructor called" << std::endl;
    collisions.clear();
    for (auto an : animations) {
        delete an.second;
    }
    std::cout << "Sprite: deleted animations" << std::endl;
}

bool Sprite::addAnimation(Animation* animation) {
    bool res = animations.insert(std::make_pair(animation->getName(), animation)).second;
    if (res && currentAnimation.empty()) {
        currentAnimation = animation->getName();
    }
    return res;
}

bool Sprite::setCurrentAnimation(std::string aname) {
    if (animations.count(aname) != 0) {
        currentAnimation = aname;
        return true;
    } else {
        return false;
    }
}

void Sprite::update() {
    if(collisionHandler) {
        handleCollisions();
    }
    animate();
}

void Sprite::draw() const {
    if (visible) {
        texture.get()->draw(GameEngine::getInstance()->getRenderer(), &cropRect, &boundingRect);
    }
}

void Sprite::collision(Sprite *s) {
    if(testCollision(s)) {
        if(collisionHandler) {
            collisions.insert(s);
        }
        if(s->isCollisionHandler()) {
            s->addCollider(this);
        }
    }
}

void Sprite::addCollider(Sprite *s) {
    collisions.insert(s);
}

bool Sprite::operator==(const Sprite &other) const {
//    return texture == other.texture && boundingRect == other.boundingRect;
    return texture == other.texture &&
            (boundingRect.x == other.boundingRect.x && boundingRect.y == other.boundingRect.y
             && boundingRect.w == other.boundingRect.w && boundingRect.h == other.boundingRect.h);
}

void Sprite::animate() {
    cropRect = *(animations[currentAnimation]->animate());
}

bool Sprite::collisionRect(Sprite *s) {
    return false;
}

bool Sprite::collisionCirc(Sprite *s) {
    return false;
}

bool Sprite::testCollision(Sprite *s) {
    return false;
}

#ifdef DEBUG_BUILD
std::string Sprite::toString() {
    std::string sep (", ");
    std::stringstream ss;
    ss << "Sprite: boundingRect: {" << boundingRect.x << sep << boundingRect.y << sep << boundingRect.w << sep << boundingRect.h << "} ";
    ss << "visible: " << visible << "\n";
    ss << "    cropRect: {" << cropRect.x << sep << cropRect.y << sep << cropRect.w << sep << cropRect.h << "} \n";
    ss << "    texture: " << texture;
    ss << "    current animation: " << currentAnimation << "\n";
    return ss.str();
}

#endif

/*
void Sprite::setCropRect(const SDL_Rect &cropRect) {
    Sprite::cropRect = cropRect;
}
*/

}