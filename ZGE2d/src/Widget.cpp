//
// Created by Victor Sago on 2018-01-17.
//

#include "Widget.hpp"

namespace zge2d {

Widget::Widget(int x, int y, int w, int h, bool visibility) : Entity(x, y, w, h, visibility) { }

Widget::Widget(const SDL_Rect& r, bool visibility) : Entity(r, visibility) { }


}
