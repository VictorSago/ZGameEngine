//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_IEVENTHANDLER_HPP
#define ZGE2D_IEVENTHANDLER_HPP

#include "SDL2/SDL.h"

namespace zge2d {

/** \brief An abstract interface class for handling of events
 *  None of the event-handling methods is implemented.
 *  Inheriting classes must override methods handling specific events.
 */
class IEventHandler {
    protected:
        virtual ~IEventHandler() = default;

    public:
        /** \brief Method for handling events
         *  It is called from an event loop and delegates
         *  specific events to corresponding methods
         */
        virtual inline bool handleEvent(SDL_Event &event);
        virtual inline bool onQuit() { return false; }
        virtual inline bool onWindowEvent(SDL_Event &event) { return false; }
        virtual inline bool onKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode) { return false; }
        virtual inline bool onKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode) { return false; }
        virtual inline bool onMouseDown(Uint8 mbutton, Sint32 x, Sint32 y, Uint8 clicks) { return false; }
        virtual inline bool onMouseUp(Uint8 mbutton, Sint32 x, Sint32 y, Uint8 clicks) { return false; }
        virtual inline bool onMouseMove(Sint32 xPos, Sint32 yPos, Sint32 xRel, Sint32 yRel, Uint32 state) { return false; }
        virtual inline bool onMouseWheel(Sint32 x, Sint32 y) { return false; }

        /** \brief Method for handling key presses outside an event loop
         *
         * \param keyState const Uint8*
         */
//        virtual void onKeyPress(const Uint8 *keyState) {}
};

bool IEventHandler::handleEvent(SDL_Event &event) {
    bool ret = false;
    switch (event.type) {
        case SDL_QUIT:
            return onQuit();
        case SDL_WINDOWEVENT:
            ret = onWindowEvent(event);
            break;
        case SDL_KEYDOWN:
            ret = onKeyDown(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.scancode);
            break;
        case SDL_KEYUP:
            ret = onKeyUp(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.scancode);
            break;
        case SDL_MOUSEBUTTONDOWN:
            ret = onMouseDown(event.button.button, event.button.x, event.button.y, event.button.clicks);
            break;
        case SDL_MOUSEBUTTONUP:
            ret = onMouseUp(event.button.button, event.button.x, event.button.y, event.button.clicks);
            break;
        case SDL_MOUSEMOTION:
            ret = onMouseMove(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel, event.motion.state);
            break;
        case SDL_MOUSEWHEEL:
            ret = onMouseWheel(event.wheel.x, event.wheel.y);
            break;
        default:
            break;
    }
    return ret;
}

}

#endif //ZGE2D_IEVENTHANDLER_HPP
