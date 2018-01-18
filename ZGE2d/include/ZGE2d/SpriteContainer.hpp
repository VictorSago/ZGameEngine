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

        GroupMap groups{};

    protected:
//        GroupIterator find(std::string gname);

    public:
        SpriteContainer() = default;
        virtual ~SpriteContainer();

        virtual bool addGroup(SpriteGroup *group);
        virtual bool addGroup(SpriteGroup *group, unsigned int z);
        virtual bool contains(const std::string& groupName) const;
        virtual bool remove(SpriteGroup* group);
        virtual bool remove(const std::string& groupName);

        virtual GroupMap& getGroups() { return groups; }

        virtual void update();
        virtual void draw(SDL_Renderer* renderTarget);

        virtual bool delegateEvent(SDL_Event& event);

        bool testCollisions();
};

}


#endif //ZGE2D_SPRITECONTAINER_HPP
