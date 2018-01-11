//
// Created by Victor Sago on 2018-01-10.
//

#include <string>
#include "VisComp.hpp"

namespace zge2d {


VisComp::VisComp(int x, int y, int w, int h, bool visibility) : boundingRect{x, y, w, h}, visible(visibility) {
//    boundingRect = {x, y, w, h};
//    visible = visibility;
}

VisComp::VisComp(const SDL_Rect &r, bool visibility) : boundingRect(r), visible(visibility) {
}

#ifdef DEBUG
std::string VisComp::toString() {
    std::string sep (", ");
    std::stringstream ss;
    ss << "VisComp: boundingRect: {" << boundingRect.x << sep << boundingRect.y << sep << boundingRect.w << sep << boundingRect.h << "} ";
    ss << "visible: " << visible << "\n";
    return ss.str();
}
#endif


}
