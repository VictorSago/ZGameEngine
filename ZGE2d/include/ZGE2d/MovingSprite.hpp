//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_MOVINGSPRITE_HPP
#define ZGE2D_MOVINGSPRITE_HPP

#include <iostream>
#include <string>

#include "Sprite.hpp"
//#include "GameEngine.hpp"

namespace zge2d {

//class GameEngine;

class MovingSprite : public Sprite {
    protected:
        /** \brief Movement vector
         * For the sake of convenience and speed the movement vector
         * is defined by three values: two to determine direction and
         * one for speed value.
         */
        float moveSpeed;
        double moveDirX = 0.0f;
        double moveDirY = 0.0f;

        double faceDir;
        SDL_RendererFlip flip = SDL_FLIP_NONE;

    public:
        MovingSprite(SDL_Renderer* renderTarget, int x, int y, int w, int h, const std::string& imagePath, bool visibility);
        virtual ~MovingSprite();

        float getMoveSpeed() { return moveSpeed; }
        virtual void setMoveSpeed(float speed) { moveSpeed = speed; }
        double getMoveDirX() { return moveDirX; }
        double getMoveDirY() { return moveDirY; }
        virtual void setMoveDir(double dirX, double dirY);

        virtual double getFaceDir() { return faceDir; }
        virtual double setFaceDir(double angle);
        virtual double setFaceDir(double dirX, double dirY);

        virtual void setFlip(SDL_RendererFlip f);

//        virtual void setDirections(int south, int west, int north, int east);
//        virtual void move(float deltaTime);
        virtual void move();
//        virtual void update(float deltaTime, bool active);
//        virtual void update(float deltaTime);
        void update() override;
        void draw(SDL_Renderer* renderTarget) const override;

//        bool intersectsWith(BasicSprite& s);
//        bool intersectsWithCirc(BasicSprite& s);

#ifdef DEBUG_BUILD
    public:
        std::string toString() override ;

#endif
};

}

#endif // ZGE2D_MOVINGSPRITE_HPP
