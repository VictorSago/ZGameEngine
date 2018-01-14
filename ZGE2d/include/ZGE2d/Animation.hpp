//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_ANIMATION_HPP
#define ZGE2D_ANIMATION_HPP

#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "Timer.hpp"

namespace zge2d {

typedef std::vector<SDL_Rect> Frames;

class Animation {
    private:
        std::string name;
        Frames clips;                   // @TODO Make into a pointer

        Timer animationTimer;

        unsigned long currentFrame;
        unsigned long maxFrames;
        int frameInc;

    public:
        Animation();
        Animation(std::string aname, Frames& c);
        Animation(std::string aname, Frames& c, unsigned int fps);
        virtual ~Animation();

        std::string getName() { return name; }
        ulong getCurrentFrame() const { return currentFrame; }
        void setCurrentFrame(int frame) { currentFrame = (frame < 0) ? 0 : frame % maxFrames; }
        ulong getMaxFrames() const { return maxFrames; }
        void setMaxFrame(ulong m) { maxFrames = m; }

        void setClips(Frames& c);

        void setFrameRateFPS(unsigned int f);
        void setFrameRateMs(Uint32 ms);

        const SDL_Rect* animate();

        void start();
        void stop();
        bool isRunning() const;

    private:

        Animation(const Animation& other);
        Animation& operator=(const Animation& other);

#ifdef DEBUG_BUILD
    public:
        std::string toString();
#endif

};

}

#endif //ZGE2D_ANIMATION_HPP
