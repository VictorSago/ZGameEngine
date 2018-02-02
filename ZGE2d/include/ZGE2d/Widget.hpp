//
// Created by Victor Sago on 2018-01-17.
//

#ifndef ZGE2D_WIDGET_HPP
#define ZGE2D_WIDGET_HPP

#include <SDL2/SDL_rect.h>

#include "Entity.hpp"

namespace zge2d {

class Widget : public Entity {
    protected:
        Widget(int x, int y, int w, int h, bool visibility = true);
        explicit Widget(const SDL_Rect& r, bool visibility = true);

    public:
        virtual ~Widget() = default;

    public:
        Widget(const Widget&) = delete;
        const Widget& operator=(const Widget&) = delete;
};

}


#endif //ZGE2D_WIDGET_HPP
