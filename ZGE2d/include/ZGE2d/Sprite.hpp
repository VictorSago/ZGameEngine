//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_BASICSPRITE_HPP
#define ZGE2D_BASICSPRITE_HPP

#include <string>
#include <memory>
#include <map>
#include <set>

#include "VisComp.hpp"
#include "Texture.hpp"
#include "Animation.hpp"

namespace zge2d {

class Sprite : public VisComp {
    protected:
        std::shared_ptr<Texture> texture;
        SDL_Rect cropRect;

        std::string currentAnimation = "";
        std::map<std::string, Animation* > animations;

        bool collisionHandler;
        std::set<Sprite*> collisions;

    public:
        Sprite(int x, int y, int w, int h, std::string imagePath, bool visibility = true);
        explicit Sprite(const SDL_Rect &r, std::string imagePath, bool visibility = true);
        virtual ~Sprite();

        const SDL_Rect& getCropRect() const { return cropRect; }
        void setCropRect(const SDL_Rect& newCropRect) { cropRect = newCropRect; }

        bool addAnimation(Animation* animation);
        bool setCurrentAnimation(std::string aname);

        bool isCollisionHandler() { return collisionHandler; }

        void update() override;
        void draw() const override;

        virtual void handleCollisions() {}

        virtual void collision(Sprite* s);

        virtual void addCollider(Sprite* s);

        virtual bool operator ==(const Sprite& other) const;

    protected:
        virtual void animate();

        virtual bool collisionRect(Sprite* s);
        virtual bool collisionCirc(Sprite* s);
        virtual bool testCollision(Sprite* s);

#ifdef DEBUG_BUILD
    public:
        /** \brief A textual representation of a sprite object
         * The toString() function can be used for debugging purposes.
         * \return A string representing this sprite
         */
        virtual std::string toString();
#endif
};

}

#endif //ZGE2D_BASICSPRITE_HPP
