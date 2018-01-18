//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>

#include "WidgetContainer.hpp"

namespace zge2d {

WidgetContainer::WidgetContainer() {
    std::cout << "WidgetContainer constructor.\n";
    widgets = new WidgetVector();
}

WidgetContainer::~WidgetContainer() {
    std::cout << "WidgetContainer destructor.\n";
    for (auto it : *widgets) {
        delete it;
    }
    widgets->clear();
    delete widgets;
}

void WidgetContainer::add(Widget* widget) {
    widgets->push_back(widget);
    size = widgets->size();
}

void WidgetContainer::remove(Widget* widget) {
    // @TODO: Rework
    for (unsigned int i = 0; i < size; i++) {
        if ((*widgets)[i] == widget) {
            widgets->erase(widgets->begin() + i);
        }
    }
    size = widgets->size();
}

bool WidgetContainer::contains(Widget* widget) {
    // @TODO: Rework
    for (unsigned int i = 0; i < size; i++) {
        if ((*widgets)[i] == widget) {
            return true;
        }
    }
    return false;
}

void WidgetContainer::empty() {
    for (auto it : *widgets) {
        delete it;
    }
    widgets->clear();
    size = widgets->size();
}

/*
bool WidgetContainer::operator==(const WidgetContainer &other) const {
    return size == other.size;
}
*/

void WidgetContainer::setVisibleAll(bool v) {
    for (auto w : *widgets) {
        w->setVisible(v);
    }
}

void WidgetContainer::setVisible(int idx, bool v) {
    (*widgets)[idx]->setVisible(v);
}

bool WidgetContainer::delegateEvent(SDL_Event &event) {
    bool handled = false;
    for (auto w : *widgets) {
        if (!handled) {
            handled = w->handleEvent(event);
        }
    }
    return handled;
}

void WidgetContainer::update() {
    if (!widgets->empty()) {          // @FIXME: Is it necessary?
        for (auto w : *widgets) {
            w->update();
        }
    }
}

void WidgetContainer::draw(SDL_Renderer* renderTarget) {
    if (!widgets->empty()) {          // @FIXME: Is it necessary?
        for (auto w : *widgets) {
            w->draw(renderTarget);
        }
    }
}

}
