//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_SESSION_HPP
#define ZGE2D_SESSION_HPP

#include <vector>

#include "VisComp.hpp"
#include "Timer.hpp"
#include "IEventHandler.hpp"

namespace zge2d {

class Session : public IEventHandler {
    private:
        std::vector<VisComp* > components;

        bool quit = false;

        Timer timer;
    public:
        Session() = default;
        virtual ~Session();

        void addElement(VisComp *comp);

        void run();
        void stop();

        void doQuit() override;
};

}

#endif //ZGE2D_SESSION_HPP
