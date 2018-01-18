//
// Created by Victor Sago on 2018-01-17.
//

#ifndef ZGE2D_WIDGET_HPP
#define ZGE2D_WIDGET_HPP

#include <SDL2/SDL_rect.h>

#include "VisEntity.hpp"

namespace zge2d {


class Widget : public VisEntity {
    protected:
        Widget(int x, int y, int w, int h, bool visibility = true) : VisEntity(x, y, w, h, visibility) {}
        explicit Widget(const SDL_Rect& r, bool visibility = true) : VisEntity(r, visibility) {}

    public:
        virtual ~Widget() = default;

//        bool handleEvent(SDL_Event &event) override {
//            return IEventHandler::handleEvent(event);
//        }

    public:
        Widget(const Widget&) = delete;
        const Widget& operator=(const Widget&) = delete;
};

}


#endif //ZGE2D_WIDGET_HPP
