//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_VISUALCOMPONENT_HPP
#define ZGE2D_VISUALCOMPONENT_HPP

#include <SDL2/SDL.h>

namespace zge2d {

class VisComp {
    private:
        SDL_Rect boundingRect;
        bool visible;
    protected:
        VisComp(int x, int y, int w, int h, bool visibility = true);
        explicit VisComp(const SDL_Rect& r, bool visibility = true);

    public:
        virtual ~VisComp() = default;

        const SDL_Rect& getBoundingRect() const {
            return boundingRect;
        }
        void setBoundingRect(SDL_Rect& rect) {
            this->boundingRect = rect;
        }

        virtual void mouseDown(const SDL_Event& eve) {}
        virtual void mouseUp(const SDL_Event& eve) {}
        virtual void keyDown(const SDL_Event& eve) {}
        virtual void keyUp(const SDL_Event& eve) {}

        virtual void drawComponent() const = 0;

#ifdef DEBUG
        /** @brief A textual representation of a visual component
         * The toString() function can be used for debugging purposes.
         * @return A string representing this object
         */
        virtual std::string toString();
#endif

    public:
        VisComp(const VisComp&) = delete;
        const VisComp& operator=(const VisComp&) = delete;

};

}

#endif //ZGE2D_VISUALCOMPONENT_HPP
