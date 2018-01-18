//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>

#include "SpriteGroup.hpp"

namespace zge2d {

SpriteGroup::SpriteGroup(const std::string& gname) {
    std::cout << "SpriteGroup constructor.\n";
    sprites = new SpriteVector();
    name = gname;
}

SpriteGroup::~SpriteGroup() {
    std::cout << "SpriteGroup destructor.\n";
    for (auto it : *sprites) {
        delete it;
    }
    sprites->clear();
}
/*
SpriteGroup SpriteGroup::copyGroup() {
    SpriteGroup new_group;
    for(unsigned int i = 0; i < size; i++) {
        new_group.add(sprites[i]);
    }
    return new_group;
}
*/

void SpriteGroup::add(Sprite* sprite) {
    std::cout << "Adding Sprite to SpriteGroup " << name << std::endl;
    sprites->push_back(sprite);
    size = sprites->size();
}

void SpriteGroup::remove(Sprite* sprite) {
    // @TODO: Rework
    for (unsigned int i = 0; i < size; i++) {
        if ((*sprites)[i] == sprite) {
            sprites->erase(sprites->begin() + i);
        }
    }
    size = sprites->size();
}

bool SpriteGroup::contains(Sprite* sprite) const {
    // @TODO: Rework
    for (unsigned int i = 0; i < size; i++) {
        if ((*sprites)[i] == sprite) {
            return true;
        }
    }
    return false;
}

void SpriteGroup::emptyGroup() {
    for (auto it : *sprites) {
        delete it;
    }
    sprites->clear();
    size = sprites->size();
}

/*
bool SpriteGroup::operator==(const SpriteGroup &other) const {
    return name == other.name && size == other.size;
}
*/

void SpriteGroup::setVisibleAll(bool v) {
    for(auto s : *sprites) {
        s->setVisible(v);
    }
}

void SpriteGroup::setVisible(int idx, bool v) {
    (*sprites)[idx]->setVisible(v);
}

bool SpriteGroup::delegateEvent(SDL_Event& event) {
    for (auto s : *sprites) {
        s->handleEvent(event);
    }
}

void SpriteGroup::update() {
    if(!sprites->empty()) {          // @FIXME: Is it necessary?
        for(auto s : *sprites) {
            s->update();
        }
    }
}

void SpriteGroup::draw(SDL_Renderer* renderTarget) {
    if(!sprites->empty()) {          // @FIXME: Is it necessary?
        for(auto s : *sprites) {
            s->draw(renderTarget);
        }
    }
}

// @EXPERIMENTAL
bool SpriteGroup::testIntersectInGroup() {
    if(size < 2)
        return false;
    bool ret = false;
    for(unsigned int i = 0; i < size; i++) {
        for(unsigned int j = i+1; j < size; j++) {
            Sprite* sprite1 = (*sprites)[i];
            Sprite* sprite2 = (*sprites)[j];
            sprite1->collision(sprite2);
//            bool temp = sprite1->collision(sprite2);
//            ret = ret || temp;
        }
    }
    return ret;
}

// @EXPERIMENTAL
SpriteVector SpriteGroup::vicinity(SDL_Rect &area) {
    SpriteVector ret;
    for(unsigned int i = 0; i < size; i++) {
        const SDL_Rect& rect = (*sprites)[i]->getBoundingRect();
        if(SDL_HasIntersection(&area, &rect)) {
            ret.push_back((*sprites)[i]);
        }
    }
    return ret;
}

}
