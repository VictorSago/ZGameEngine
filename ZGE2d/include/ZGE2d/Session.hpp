//
// Created by Victor Sago on 2018-01-10.
//

#ifndef ZGE2D_SESSION_HPP
#define ZGE2D_SESSION_HPP

#include <unordered_map>
#include <vector>

#include "Definitions.hpp"
#include "Timer.hpp"
#include "IEventHandler.hpp"
#include "GameWindow.hpp"

namespace zge2d {



class Session : public IEventHandler {
    private:
        bool quit = false;
        Timer timer;

//        const Uint8* keyState;

    protected:
        std::unordered_map<std::string, GameWindow* > windows;    /**< All game windows (or game states) */
        GameWindow* currentWindow = nullptr;                      /**< The pointer to the current window/game state */

    public:
        Session();
        virtual ~Session();

        virtual GameWindow* newWindow(const std::string& winTitle);
        virtual GameWindow* newWindow(const std::string& winName, const std::string& winTitle);
        virtual GameWindow* newWindow(const std::string& winName, const std::string& winTitle,
                                      SDL_Color bgColor, unsigned int w, unsigned int h);
        virtual GameWindow* newWindow(const std::string& winName, const std::string& winTitle,
                                      const std::string& bg_image, unsigned int w, unsigned int h);
        virtual GameWindow* newWindow(const std::string& winName, const std::string& winTitle,
                                      const std::string& bg_image, SDL_Color, unsigned int w, unsigned int h);


        void run();
        void stop();

        Timer* getMainTimer() { return &timer; }
    protected:
        bool onQuit() override;

};

}

#endif //ZGE2D_SESSION_HPP
