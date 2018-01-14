//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_SPRITECONTAINER_HPP
#define ZGE2D_SPRITECONTAINER_HPP

#include <string>

#include "SpriteGroup.hpp"

namespace zge2d {

typedef std::pair<unsigned int, std::string > GroupKey;
typedef std::map<GroupKey, SpriteGroup* > GroupMap;
typedef GroupMap::iterator GroupIterator;

class SpriteContainer {
    private:
        unsigned int nextZ = 0;

        GroupMap groups;

    protected:
//        GroupIterator find(std::string gname);

    public:
        SpriteContainer() = default;
        virtual ~SpriteContainer();

        virtual bool add(SpriteGroup* group);
        virtual bool add(unsigned int z, SpriteGroup* group);
        virtual bool contains(std::string groupName);
        virtual bool remove(SpriteGroup* group);
        virtual bool remove(std::string groupName);

        virtual void update();
        virtual void draw();

        bool testCollisions();
};

}


#endif //ZGE2D_SPRITECONTAINER_HPP
