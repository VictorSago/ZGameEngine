//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_GAMEWINDOW_HPP
#define ZGE2D_GAMEWINDOW_HPP

#include <string>
#include <memory>

#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "SpriteContainer.hpp"
#include "WidgetContainer.hpp"

namespace zge2d {

class GameWindow : protected IEventHandler {
    private:
        std::string name;       /**< Used to reference the window in the code and store it in a map. */
        std::string title;      /**< Window's title */
        unsigned int width, height;

        bool background;        /**< Indicates whether the window's background should be displayed. */

        SDL_Window *window = nullptr;
        SDL_Renderer *renderTarget = nullptr;
        std::shared_ptr<Texture> bgImage = nullptr;
        SDL_Color bgColor;

        SpriteContainer* sprites;
        WidgetContainer* widgets;

    public:
        explicit GameWindow(const std::string& winTitle);
        GameWindow(const std::string& winName, const std::string& winTitle, SDL_Color bg_color);
        GameWindow(const std::string& winName, const std::string& winTitle, SDL_Color bg_color, unsigned int w, unsigned int h);
        GameWindow(const std::string& winName, const std::string& winTitle, const std::string& bg_image);
        GameWindow(const std::string& winName, const std::string& winTitle, const std::string& bg_image,
                   unsigned int w, unsigned int h);
        GameWindow(const std::string& winName, const std::string& winTitle, const std::string& bg_image,
                   SDL_Color bg_color, unsigned int w, unsigned int h);
        virtual ~GameWindow();

        std::string getName() const { return name; }
        std::string getTitle() const { return title; }
        void setTitle(const std::string& newTitle) { SDL_SetWindowTitle(window, newTitle.c_str()); }
        unsigned int getWidth() const { return width; }
        unsigned int getHeight() const { return height; }
        bool hasBackground() const { return background; }
        SDL_Renderer* getRenderer() const { return renderTarget; }

        void addWidget(Widget* w) { widgets->add(w); }
        void addSpriteGroup(SpriteGroup* sg) { sprites->addGroup(sg); }
//        SpriteContainer* getSpriteContainer() { return sprites; }
//        WidgetContainer* getWidgetContainer() { return widgets; }

//        void updateSprites(float deltaTime, const Uint8 *keyState);
        virtual void updateSprites();
        virtual void update();
        virtual void draw();

    public:
        bool handleEvent(SDL_Event& event) override;

    protected:
        bool onWindowEvent(SDL_Event& event) override;

};

}

#endif //ZGE2D_GAMEWINDOW_HPP
