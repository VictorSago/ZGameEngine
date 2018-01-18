//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_VISENTITY_HPP
#define ZGE2D_VISENTITY_HPP

#include <SDL2/SDL.h>
#include "IEventHandler.hpp"

namespace zge2d {

class VisEntity : public IEventHandler {
    protected:
        SDL_Rect boundingRect;
        bool visible;
    protected:
        VisEntity(int x, int y, int w, int h, bool visibility = true);
        explicit VisEntity(const SDL_Rect& r, bool visibility = true);

    public:
        virtual ~VisEntity() = default;

        const SDL_Rect& getBoundingRect() const { return boundingRect; }
        void setBoundingRect(SDL_Rect& rect) { boundingRect = rect; }

        int getX() const { return boundingRect.x; }
        int getY() const { return boundingRect.y; }
        void setXY(int x, int y) { boundingRect.x = x; boundingRect.y = y; }

        int getW() const { return boundingRect.w; }
        int getH() const { return boundingRect.h; }
        void setWH(int w, int h) { boundingRect.w = w; boundingRect.h = h; }

        virtual bool isVisible() const { return visible; }
        virtual void setVisible(const bool v) { visible = v; }

    public:
//        virtual void mouseDown(const SDL_Event& eve) {}
//        virtual void mouseUp(const SDL_Event& eve) {}
//        virtual void keyDown(const SDL_Event& eve) {}
//        virtual void keyUp(const SDL_Event& eve) {}

        virtual void update() = 0;
        virtual void draw(struct SDL_Renderer* renderTarget) const = 0;

    public:
        VisEntity(const VisEntity&) = delete;
        virtual const VisEntity& operator=(const VisEntity&) = delete;

#ifdef DEBUG_BUILD
        /** @brief A textual representation of a visual component
         * The toString() function can be used for debugging purposes.
         * @return A string representing this object
         */
        virtual std::string toString();
#endif

};

}

#endif //ZGE2D_VISUALCOMPONENT_HPP
