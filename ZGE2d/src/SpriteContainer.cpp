//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>

#include "SpriteContainer.hpp"

namespace zge2d {

SpriteContainer::~SpriteContainer() {
    std::cout << "Entering SpriteContainer destructor." << std::endl;
    for(auto& it : groups) {
        if (it.second != nullptr) {
            std::cout << "Deleting member SpriteGroup \'"<< it.second->getName() << "\'" << std::endl;
            delete it.second;
        }
    }
    groups.clear();
}

bool SpriteContainer::addGroup(SpriteGroup *group) {
    return addGroup(group, nextZ + 1);
}

bool SpriteContainer::addGroup(SpriteGroup *group, unsigned int z) {
    std::string groupName = group->getName();
    if(!contains(groupName)) {
        GroupKey key(z, groupName);
        nextZ = std::max(nextZ, z);
        return groups.insert(std::make_pair(key, group)).second;
    }
    return false;
}

bool SpriteContainer::contains(const std::string& groupName) const {
    for(const auto& it : groups) {
        if(it.first.second == groupName) {
            return true;
        }
    }
    return false;
}

bool SpriteContainer::remove(SpriteGroup* group) {
    std::string groupName = group->getName();
    return remove(groupName);
}

bool SpriteContainer::remove(const std::string& groupName) {
    for(auto it = groups.begin(); it != groups.end(); ++it) {
        if(it->first.second == groupName) {
            groups.erase(it);
            return true;
        }
    }
    return false;
}

void SpriteContainer::update() {
    testCollisions();
    for(auto& it : groups) {
        it.second->update();
    }
}

void SpriteContainer::draw(SDL_Renderer* renderTarget) {
    for(const auto& it : groups) {
        it.second->draw(renderTarget);
    }
}

bool SpriteContainer::testCollisions() {
    bool ret = false;
    SpriteVector collisionVec;
    for (auto g1 = groups.rbegin(); g1 != groups.rend(); ++g1) {
//        std::cout << "Group: " << g1->first.first << ", \'" << g1->second->getName() << "\'\n";
        for (auto& s1 : *g1->second->getSprites()) {
//            Sprite* sprite0_ptr = s1;
//            std::cout << "Sprite: " << sprite0_ptr->toString() << "\n";
            collisionVec.push_back(s1);
        }
    }
    for (unsigned int i = 0; i < collisionVec.size(); i++) {
        for (unsigned int j = i + 1; j < collisionVec.size(); j++) {
            collisionVec[i]->collision(collisionVec[j]);
//            Sprite *sprite1 = collvec[i];
//            Sprite *sprite2 = collvec[j];
//            sprite1->collision(sprite2);
        }
    }
    return ret;
}

inline
bool SpriteContainer::delegateEvent(SDL_Event& event) {
    bool handled = false;
    for (auto sg : groups) {
        handled = sg.second->delegateEvent(event);
    }
    return handled;
}

}
