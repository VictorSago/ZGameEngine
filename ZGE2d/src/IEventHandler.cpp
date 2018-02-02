//
// Created by Victor Sago on 2018-02-01.
//

#include "IEventHandler.hpp"

namespace zge2d {

bool IEventHandler::handleEvent(SDL_Event& event) {
    bool handled = false;
    auto fPtr = eventMap.find(event.type);
    if (fPtr != eventMap.end()) {
//        handled = fPtr->second(this, event);
        handled = fPtr->second(event);
    } else {
        switch (event.type) {
            case SDL_QUIT:
                return onQuit();
            case SDL_WINDOWEVENT:
                handled = onWindowEvent(event);
                break;
            case SDL_KEYDOWN:
                handled = onKeyDown(event);
//            ret = onKeyDown(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.scancode);
                break;
            case SDL_KEYUP:
                handled = onKeyUp(event);
//            ret = onKeyUp(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.scancode);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handled = onMouseDown(event);
//            ret = onMouseDown(event.button.button, event.button.x, event.button.y, event.button.clicks);
                break;
            case SDL_MOUSEBUTTONUP:
                handled = onMouseUp(event);
                break;
            case SDL_MOUSEMOTION:
                handled = onMouseMove(event);
//            ret = onMouseMove(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel, event.motion.state);
                break;
            case SDL_MOUSEWHEEL:
                handled = onMouseWheel(event);
//            ret = onMouseWheel(event.wheel.x, event.wheel.y);
                break;
            default:
                break;
        }
    }
    return handled;
}

bool IEventHandler::registerEventHandler(SDL_EventType eventType, EventHandler_f handlerFunc) {
    return eventMap.emplace(eventType, handlerFunc).second;
}

}
