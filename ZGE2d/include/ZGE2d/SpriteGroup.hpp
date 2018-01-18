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
        SpriteVector* sprites;
        unsigned long size = 0;

    protected:
        SpriteGroup() {}

    public:
        explicit SpriteGroup(const std::string& gname);
        virtual ~SpriteGroup();

//        SpriteGroup copyGroup();

        std::string getName() const { return name; }

        SpriteVector* getSprites() { return sprites; }

        virtual void add(Sprite* sprite);
        virtual void remove(Sprite* sprite);
        bool contains(Sprite* sprite) const;
        virtual void emptyGroup();

        long getSize() const { return size; }

//        virtual bool operator==(const SpriteGroup& other) const;

        void setVisibleAll(bool v);
        void setVisible(int idx, bool v);

//        void update(float deltaTime, const Uint8 *keyState);
        void update();
        void draw(SDL_Renderer* renderTarget);

        virtual bool delegateEvent(SDL_Event& event);

        bool testIntersectInGroup();

        virtual SpriteVector vicinity(SDL_Rect& area);
};

}

#endif //ZGE2D_SPRITEGROUP_HPP
