//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>
#include <utility>
#ifdef DEBUG_BUILD
    #include <sstream>
#endif

#include "Definitions.hpp"
#include "Animation.hpp"

namespace zge2d {

Animation::Animation() {
    std::cout << "Animation constructor 0." << std::endl;
    name = "Unnamed";
    currentFrame = 0;
    maxFrames = 0;
    frameInc = 1;
    animationTimer.setFPS(defaultFPS / 6);
}

Animation::Animation(const std::string& aname, Frames &c) : Animation(aname, c, defaultFPS / 6) {}

Animation::Animation(const std::string& aname, Frames &c, unsigned int fps) : name(aname), clips(c) {
    std::cout << "Animation constructor 3: " << name << "." << std::endl;
    currentFrame = 0;
    maxFrames = c.size();
    frameInc = 1;
    animationTimer.setFPS(fps);
}

Animation::~Animation() {
    std::cout << "Animation destructor 0." << std::endl;
}

void Animation::setClips(Frames &c) {
    for (auto cp : c) {
        clips.push_back(cp);
    }
    maxFrames = clips.size();
}

void Animation::setFrameRateFPS(unsigned int f) {
    animationTimer.setFPS(f);
}

void Animation::setFrameRateMs(Uint32 ms) {
    animationTimer.setTickInterval(ms);
}

const SDL_Rect* Animation::animate() {
    if (clips.empty()) {
        return nullptr;
    }
    if (animationTimer.isStarted()) {
        if (animationTimer.isNext()) {
            animationTimer.update();
            currentFrame += 1;

            if (currentFrame >= maxFrames) {
                currentFrame = 0;
            }
        }
    } else {
        animationTimer.start();
        currentFrame = 0;
    }
    return &clips[currentFrame];
}

void Animation::start() {
    animationTimer.start();
}

void Animation::stop() {
    animationTimer.stop();
}

bool Animation::isRunning() const {
    return animationTimer.isStarted();
}

#ifdef DEBUG_BUILD
std::string Animation::toString() {
    std::string sep (", ");
    std::stringstream ss;
    ss << "Animation: " << name << "\n";
    return ss.str();
}
#endif

}