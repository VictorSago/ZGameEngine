//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_VISENTITY_HPP
#define ZGE2D_VISENTITY_HPP

#include <SDL2/SDL.h>
#include "IEventHandler.hpp"

namespace zge2d {

class Entity : public IEventHandler {
    protected:
        SDL_Rect boundingRect;
        bool visible;
    protected:
        Entity(int x, int y, int w, int h, bool visibility = true);
        explicit Entity(const SDL_Rect& r, bool visibility = true);

    public:
        virtual ~Entity() = default;

        const SDL_Rect& getBoundingRect() const { return boundingRect; }
        void setBoundingRect(SDL_Rect& rect) { boundingRect = rect; }
        void setBoundingRect(int xPos, int yPos, int width, int height);

        int getX() const { return boundingRect.x; }
        int getY() const { return boundingRect.y; }
        void setXY(int x, int y) { boundingRect.x = x; boundingRect.y = y; }

        int getW() const { return boundingRect.w; }
        int getH() const { return boundingRect.h; }
        void setWH(int w, int h) { boundingRect.w = w; boundingRect.h = h; }

        virtual bool isVisible() const { return visible; }
        virtual void setVisible(const bool v) { visible = v; }

    public:
        virtual void update() = 0;
        virtual void draw(struct SDL_Renderer* renderTarget) const = 0;

    public:
        Entity(const Entity&) = delete;
        virtual const Entity& operator=(const Entity&) = delete;

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
