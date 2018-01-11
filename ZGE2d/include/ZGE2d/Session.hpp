//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_SESSION_HPP
#define ZGE2D_SESSION_HPP

#include <vector>
#include "VisComp.hpp"

namespace zge2d {

class Session {
    private:
        std::vector<VisComp* > components;
        bool quit = false;
    public:
        Session();
        virtual ~Session();

        void addComponent(VisComp* comp);

        void run();
        void stop();
};

}

#endif //ZGE2D_SESSION_HPP
