//
// Created by Victor Sago on 2018-01-17.
//

#ifndef ZGE2D_WIDGETCONTAINER_HPP
#define ZGE2D_WIDGETCONTAINER_HPP

#include <string>
#include <vector>

#include "Widget.hpp"

namespace zge2d {

typedef std::vector<Widget* > WidgetVector;

class WidgetContainer {
    protected:
        WidgetVector* widgets;
        unsigned long size = 0;

    public:
        WidgetContainer();
        virtual ~WidgetContainer();

        WidgetVector* getWidgets() { return widgets; }

        virtual void add(Widget* widget);
        virtual void remove(Widget* widget);
        bool contains(Widget* widget);
        virtual void empty();

        long getSize() { return size; }

//        virtual bool operator==(const WidgetContainer& other) const;

        void setVisibleAll(bool v);
        void setVisible(int idx, bool v);

        virtual bool delegateEvent(SDL_Event& event);

//        void update(float deltaTime, const Uint8 *keyState);
        void update();
        void draw(SDL_Renderer* renderTarget);

};

}

#endif //ZGE2D_WIDGETCONTAINER_HPP
