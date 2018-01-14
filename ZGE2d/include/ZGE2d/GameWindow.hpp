//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_GAMEWINDOW_HPP
#define ZGE2D_GAMEWINDOW_HPP

#include <string>
#include <memory>

#include <SDL2/SDL.h>

#include "Texture.hpp"

namespace zge2d {

class GameWindow {
    private:
        std::string name;       /**< Used to reference the window in the code and store it in a map. */
        std::string title;      /**< Window's title */
        unsigned int width, height;

        bool background;        /**< Indicates whether the window's background should be displayed. */

        SDL_Window *window = nullptr;
        SDL_Renderer *renderTarget = nullptr;
        std::shared_ptr<Texture> bgImage = nullptr;
        SDL_Color bgColor;

//        SpriteContainer* sprites;

    public:
        GameWindow(std::string winTitle);
        GameWindow(std::string winName, std::string winTitle, SDL_Color bgcolor);
        GameWindow(std::string winName, std::string winTitle, SDL_Color bgcolor, unsigned int w, unsigned int h);
        GameWindow(std::string winName, std::string winTitle, std::string bg_image);
        GameWindow(std::string winName, std::string winTitle, std::string bg_image, unsigned int w, unsigned int h);
        virtual ~GameWindow();

        std::string getName() const { return name; }
        std::string getTitle() const { return title; }
        unsigned int getWidth() { return width; }
        unsigned int getHeight() { return height; }
        bool hasBackground() { return background; }
        SDL_Renderer* getRenderTarget() { return renderTarget; }

//        SpriteContainer* getSprites() { return sprites; }

//        void updateSprites(float deltaTime, const Uint8 *keyState);
        virtual void updateSprites();
        virtual void update();
        virtual void draw();

};

}

#endif //ZGE2D_GAMEWINDOW_HPP
