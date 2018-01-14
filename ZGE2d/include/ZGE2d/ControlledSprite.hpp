//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_CONTROLLEDSPRITE_HPP
#define ZGE2D_CONTROLLEDSPRITE_HPP

#include <vector>
#include "MovingSprite.hpp"

namespace zge2d {

class ControlledSprite : public MovingSprite {
    protected:
        std::vector<SDL_Scancode> controls;

    public:
        ControlledSprite(int x, int y, int w, int h, std::string filePath, bool visibility);
        virtual ~ControlledSprite();

        virtual void setControls(SDL_Scancode* keys, int num);

//        virtual void update(float deltaTime, bool active);
//        virtual void update(float deltaTime);
        virtual void update();

        virtual void handleControls(const Uint8* keyState) = 0;

        virtual std::string toString();

};

} // namespace

#endif // CONTROLLEDSPRITE_HPP
