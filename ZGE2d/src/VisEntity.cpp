//
// Created by Victor Sago on 2018-01-10.
//

#include <string>
#ifdef DEBUG_BUILD
    #include <sstream>
#endif
#include "VisEntity.hpp"

namespace zge2d {

VisEntity::VisEntity(int x, int y, int w, int h, bool visibility) : boundingRect{x, y, w, h}, visible(visibility) { }

VisEntity::VisEntity(const SDL_Rect& r, bool visibility) : boundingRect(r), visible(visibility) { }


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
