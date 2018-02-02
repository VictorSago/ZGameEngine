//
// Created by Victor Sago on 2018-01-10.
//

#ifdef DEBUG_BUILD
    #include <string>
    #include <sstream>
#endif
#include "Entity.hpp"

namespace zge2d {

Entity::Entity(int x, int y, int w, int h, bool visibility) : boundingRect{x, y, w, h}, visible(visibility) { }

Entity::Entity(const SDL_Rect& r, bool visibility) : boundingRect(r), visible(visibility) { }

void Entity::setBoundingRect(int xPos, int yPos, int width, int height) {
    boundingRect.x = xPos;
    boundingRect.y = yPos;
    boundingRect.w = width;
    boundingRect.h = height;
}

#ifdef DEBUG_BUILD
std::string VisEntity::toString() {
    std::string sep (", ");
    std::stringstream ss;
    ss << "VisEntity: boundingRect: {" << boundingRect.x << sep << boundingRect.y << sep << boundingRect.w << sep << boundingRect.h << "} ";
    ss << "visible: " << visible << "\n";
    return ss.str();
}
#endif

}
