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
        virtual void handleEvent(SDL_Event& event);
        virtual void doQuit() {}
        virtual void onKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode) {}
        virtual void onKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode) {}
        virtual void onMouseDown(Uint8 mbutton, Sint32 x, Sint32 y, Uint8 clicks) {}
        virtual void onMouseUp(Uint8 mbutton, Sint32 x, Sint32 y, Uint8 clicks) {}
        virtual void onMouseMove(Sint32 xPos, Sint32 yPos, Sint32 xRel, Sint32 yRel, Uint32 state) {}

        /** \brief Method for handling key presses outside an event loop
         *
         * \param keyState const Uint8*
         */
        virtual void onKeyPress(const Uint8 *keyState) {}
};

void IEventHandler::handleEvent(SDL_Event &event) {
    switch (event.type) {
        case SDL_QUIT:
            doQuit();
            break;
        case SDL_KEYDOWN:
            onKeyDown(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.scancode);
            break;
        case SDL_KEYUP:
            onKeyUp(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.scancode);
            break;
        case SDL_MOUSEBUTTONDOWN:
            onMouseDown(event.button.button, event.button.x, event.button.y, event.button.clicks);
            break;
        case SDL_MOUSEBUTTONUP:
            onMouseUp(event.button.button, event.button.x, event.button.y, event.button.clicks);
            break;
        case SDL_MOUSEMOTION:
            onMouseMove(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel, event.motion.state);
            break;
    }
}

}

#endif //ZGE2D_IEVENTHANDLER_HPP
