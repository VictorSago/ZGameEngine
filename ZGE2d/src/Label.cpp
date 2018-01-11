//
// Created by Victor Sago on 2018-01-11.
//

#include "Label.hpp"


namespace zge2d {


Label::Label(int x, int y, int w, int h, bool visibility) : VisComp(x, y, w, h, visibility) {}


Label::Label(const SDL_Rect &r, bool visibility) : VisComp(r, visibility) {

}

}