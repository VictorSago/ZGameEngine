//
// Created by Victor Sago on 2018-01-11.
//

#include "GameEngine.hpp"
#include "Label.hpp"



namespace zge2d {


Label::Label(int x, int y, int w, int h, std::string text, std::string font, SDL_Color fgColor, int size, bool visibility)
        : VisComp(x, y, w, h, visibility), labelText(std::move(text)), fontPath(std::move(font)), textColor(fgColor), fontSize(size) {
    Texture* pTexture = Texture::makeFromText(GameEngine::getInstance()->getRenderer(), fontPath, labelText, textColor, fontSize);
    texture = std::shared_ptr<Texture>(pTexture);
}

Label::Label(const SDL_Rect &r, std::string text, std::string font, SDL_Color fgColor, int size, bool visibility)
        : VisComp(r, visibility), labelText(std::move(text)), fontPath(std::move(font)), textColor(fgColor), fontSize(size) {
    Texture* pTexture = Texture::makeFromText(GameEngine::getInstance()->getRenderer(), fontPath, labelText, textColor, fontSize);
    texture = std::shared_ptr<Texture>(pTexture);
}

Label* Label::getInstance(int x, int y, int w, int h, std::string text, std::string font, SDL_Color fgColor, int size) {
    return new Label(x, y, w, h, std::move(text), std::move(font), fgColor, size);
}

Label* Label::getInstance(const SDL_Rect &r, std::string text, std::string font, SDL_Color fgColor, int size) {
    return new Label(r, std::move(text), std::move(font), fgColor, size);
}

Label* Label::getInstance(int x, int y, std::string text, std::string font, SDL_Color fgColor, int size) {
    Label* tLbl = new Label(x, y, 0, 0, std::move(text), std::move(font), fgColor, size);
    tLbl->setWH(tLbl->texture->getWidth(), tLbl->texture->getHeight());
//    tLbl->boundingRect.w = tLbl->texture->getWidth();
//    tLbl->boundingRect.h = tLbl->texture->getHeight();
    return tLbl;
}

std::string Label::getText() const {
    return std::string();
}

void Label::setText(std::string text) {
    labelText = std::move(text);
}

int Label::getFontSize() const {
    return fontSize;
}

void Label::setFontSize(int newSize) {
    fontSize = newSize;
}

const SDL_Color& Label::getTextColor() const {
    return textColor;
}

void Label::setTextColor(const SDL_Color& color) {
    Label::textColor = color;
}

const std::string& Label::getFontPath() const {
    return fontPath;
}

void Label::setNewFont(const std::string& path) {
    fontPath = fontPath;
}

void Label::reloadTexture() {
    texture = nullptr;
    Texture* pTexture = Texture::makeFromText(GameEngine::getInstance()->getRenderer(), fontPath, labelText, textColor, fontSize);
    texture = std::shared_ptr<Texture>(pTexture);
}

void Label::update() {
}

void Label::draw() const {
//    SDL_Rect dst{boundingRect};
    texture.get()->draw(GameEngine::getInstance()->getRenderer(), nullptr, &boundingRect);
}


}