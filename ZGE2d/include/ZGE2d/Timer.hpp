//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_GAMETIMER_HPP
#define ZGE2D_GAMETIMER_HPP


#include <SDL2/SDL.h>

namespace zge2d {

class Timer {
    private:
        Uint32 currentTick;
        Uint32 prevTick;
        Uint32 tickInterval;
        unsigned int fps;           // relation between fps and tickInterval: tickInterval = 1000/fps

        bool started;
        bool paused;
        Uint32 startTime;
        Uint32 pauseTime;

    public:
        Timer();
        explicit Timer(unsigned int framesPerSec);
        virtual ~Timer();

        unsigned int getFPS() const { return fps; }
        Uint32 getTickInterval() const { return tickInterval; }

        void setFPS(unsigned int framesPerSec);
        void setTickInterval(Uint32 interval);

        void start();
        void stop();
        void pause();
        void unpause();

        Uint32 getTicks() const;
        Uint32 getDelta() const { return currentTick - prevTick; }

        bool isStarted() const { return started; }
        bool isPaused() const { return paused; }

        bool isNext() const { return SDL_GetTicks() - currentTick > tickInterval; }

        void update() { prevTick = currentTick; currentTick = SDL_GetTicks(); }
        void capFPS();
};

}

#endif //ZGE2D_GAMETIMER_HPP
