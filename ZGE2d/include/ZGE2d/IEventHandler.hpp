//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_IEVENTHANDLER_HPP
#define ZGE2D_IEVENTHANDLER_HPP

#include "SDL2/SDL.h"

#include <map>
#include <functional>

namespace zge2d {

/** \brief An abstract interface class for handling of events
 *  None of the event-handling methods is implemented.
 *  Inheriting classes must override methods handling specific events.
 */
class IEventHandler {
    public:
        typedef bool (*fptr_Handler)(IEventHandler*, SDL_Event&);
//        using EventHandler_fptr = std::function<bool(IEventHandler*, SDL_Event&)>;
        typedef std::function<bool(IEventHandler*, SDL_Event&)> EventHandler_f;

    protected:
        std::map<Uint32, EventHandler_f > eventMap;
    public:
//        bool addEventHandler(SDL_EventType eventType, fptr_Handler handlerFunc);
        bool addEventHandler(SDL_EventType eventType, EventHandler_f handlerFunc);
    protected:
        virtual ~IEventHandler() = default;

    public:
        /** \brief Method for handling events
         *  It is called from an event loop and delegates
         *  specific events to corresponding methods
         */
        virtual bool handleEvent(SDL_Event &event);
        virtual bool onQuit() { return false; }
        virtual bool onWindowEvent(SDL_Event &event) { return false; }
        virtual bool onKeyDown(SDL_Event& event) { return false; }
        virtual bool onKeyUp(SDL_Event& event) { return false; }
        virtual bool onMouseDown(SDL_Event& event) { return false; }
        virtual bool onMouseUp(SDL_Event& event) { return false; }
        virtual bool onMouseMove(SDL_Event& event) { return false; }
        virtual bool onMouseWheel(SDL_Event& event) { return false; }

/*
        virtual inline bool onWindowEvent(SDL_Event &event) { return false; }
        virtual inline bool onKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode) { return false; }
        virtual inline bool onKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode) { return false; }
        virtual inline bool onMouseDown(Uint8 mbutton, Sint32 x, Sint32 y, Uint8 clicks) { return false; }
        virtual inline bool onMouseUp(Uint8 mbutton, Sint32 x, Sint32 y, Uint8 clicks) { return false; }
        virtual inline bool onMouseMove(Sint32 xPos, Sint32 yPos, Sint32 xRel, Sint32 yRel, Uint32 state) { return false; }
        virtual inline bool onMouseWheel(Sint32 x, Sint32 y) { return false; }
*/

        /** \brief Method for handling key presses outside an event loop
         *
         * \param keyState const Uint8*
         */
//        virtual void onKeyPress(const Uint8 *keyState) {}
};

}

#endif //ZGE2D_IEVENTHANDLER_HPP
