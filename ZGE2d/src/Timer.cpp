//
// Created by Victor Sago on 2018-01-14.
//

#include <iostream>

#include "Definitions.hpp"
#include "Timer.hpp"

namespace zge2d {

Timer::Timer() : Timer(defaultFPS) {}
/*
Timer::Timer() {
    std::cout << "Timer constructor 0." << std::endl;
    fps = defaultFPS;
    tickInterval = 1000 / fps;
    currentTick = 0;
    prevTick = 0;
    startTime = 0;
    pauseTime = 0;
    started = false;
    paused = false;
}
*/

Timer::Timer(unsigned int framesPerSec) {
    std::cout << "Timer constructor 1." << std::endl;
    fps = framesPerSec;
    tickInterval = 1000 / fps;
    currentTick = 0;
    prevTick = 0;
    startTime = 0;
    pauseTime = 0;
    started = false;
    paused = false;
}

Timer::~Timer() {
    std::cout << "Timer destructor." << std::endl;
}

void Timer::setFPS(unsigned int framesPerSec) {
    if (framesPerSec < minFPS) {
        fps = minFPS;
    } else if (framesPerSec > maxFPS) {
        fps = maxFPS;
    } else {
        fps = framesPerSec;
    }
    tickInterval = 1000/framesPerSec;
}

void Timer::setTickInterval(Uint32 interval) {
    if (interval < 1000/maxFPS ) {
        tickInterval = 1000/maxFPS;
    } else if (interval > 1000/minFPS) {
        tickInterval = 1000/minFPS;
    } else {
        tickInterval = interval;
    }
    fps = 1000/tickInterval;
}

void Timer::start() {
    startTime = SDL_GetTicks();
    currentTick = startTime;
    started = true;
    paused = false;
}

void Timer::stop() {
    prevTick = currentTick = 0;
    startTime = 0;
    pauseTime = 0;
    started = false;
    paused = false;
}

void Timer::pause() {
    if (started && !paused) {
        pauseTime = SDL_GetTicks() - startTime;
        startTime = 0;
        paused = true;
    }
}

void Timer::unpause() {
    if (started && paused) {
        startTime = getTicks() - pauseTime;
        pauseTime = 0;
        paused = false;
    }
}

Uint32 Timer::getTicks() const {
    if (started) {
        if (!paused) {
            return SDL_GetTicks() - startTime;
        } else {
            return pauseTime;
        }
    } else {
        return 0;
    }
}

/*
Uint32 Timer::getTicks() {
    if (started) {
        return SDL_GetTicks() - prevTick;
    } else {
        return 0;
    }
}
*/

void Timer::capFPS() {
    update();
    int diff = prevTick + tickInterval - currentTick;
    if (diff > 0) {
        SDL_Delay(static_cast<Uint32>(diff));
    }
}

}