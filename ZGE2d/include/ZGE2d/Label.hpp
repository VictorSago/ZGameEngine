//
// Created by Victor Sago on 2018-01-11.
//

#ifndef ZGE2D_LABEL_HPP
#define ZGE2D_LABEL_HPP

#include <string>
#include <memory>

#include "Texture.hpp"
#include "Widget.hpp"

namespace zge2d {

class Label : public Widget {
    private:
        std::string labelText;

        std::string fontPath;
        int         fontSize;
        SDL_Color   textColor;

        std::shared_ptr<Texture> texture;

    protected:
        Label(SDL_Renderer* renderTarget, int x, int y, int w, int h, std::string text, std::string font, SDL_Color fgColor, int size = 16, bool visibility = true);
        Label(SDL_Renderer* renderTarget, const SDL_Rect& r, std::string text, std::string font, SDL_Color fgColor, int size = 16, bool visibility = true);

    public:
        static Label* getInstance(SDL_Renderer* renderTarget, int x, int y, int w, int h, std::string text, std::string font, SDL_Color fgColor, int size = 16);
        static Label* getInstance(SDL_Renderer* renderTarget, const SDL_Rect& r, std::string text, std::string font, SDL_Color fgColor, int size = 16);
        static Label* getInstance(SDL_Renderer* renderTarget, int x, int y, std::string text, std::string font, SDL_Color fgColor, int size = 16);

    public:
        virtual ~Label() = default;

        std::string getText() const;
        void setText(std::string text);
        int getFontSize() const;
        void setFontSize(int newSize);
        const SDL_Color& getTextColor() const;
        void setTextColor(const SDL_Color& color);
        const std::string& getFontPath() const;
        void setNewFont(const std::string& path);

        void reloadTexture(SDL_Renderer* renderTarget);
        void update() override;
        void draw(SDL_Renderer* renderTarget) const override;
};

}

#endif //ZGE2D_LABEL_HPP
