//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_SPRITEGROUP_HPP
#define ZGE2D_SPRITEGROUP_HPP

#include <string>

#include "Sprite.hpp"

namespace zge2d {

typedef std::vector<Sprite* > SpriteVector;

class SpriteGroup {
    protected:
        std::string name;
        SpriteVector sprites;
        unsigned long size = 0;

    protected:
        SpriteGroup() {}

    public:
        SpriteGroup(std::string gname);
        virtual ~SpriteGroup();

//        SpriteGroup copyGroup();

        std::string getName() { return name; }

        SpriteVector& getSprites() { return sprites; }

        virtual void add(Sprite *sprite);
        virtual void remove(Sprite *spr);
        bool contains(Sprite *spr);
        virtual void emptyGroup();

        long getSize() { return size; }

        virtual bool operator==(const SpriteGroup& other) const;

        void setVisibleAll(bool v);
        void setVisible(int idx, bool v);

//        void update(float deltaTime, const Uint8 *keyState);
        void update();
        void draw();

        bool testIntersectInGroup();

        virtual SpriteVector vicinity(SDL_Rect& area);
};

}

#endif //ZGE2D_SPRITEGROUP_HPP
