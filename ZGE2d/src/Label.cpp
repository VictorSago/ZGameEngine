//
// Created by Victor Sago on 2018-01-11.
//

#include <iostream>
#include "GameEngine.hpp"
#include "Label.hpp"


namespace zge2d {


Label::Label(SDL_Renderer* renderTarget, int x, int y, int w, int h, std::string text, std::string font, SDL_Color fgColor, int size, bool visibility)
        : Widget(x, y, w, h, visibility), labelText(std::move(text)), fontPath(std::move(font)), textColor(fgColor), fontSize(size) {
    Texture* pTexture = Texture::makeFromText(renderTarget, fontPath, labelText, textColor, fontSize);
    texture = std::shared_ptr<Texture>(pTexture);
}

Label::Label(SDL_Renderer* renderTarget, const SDL_Rect &r, std::string text, std::string font, SDL_Color fgColor, int size, bool visibility)
        : Widget(r, visibility), labelText(std::move(text)), fontPath(std::move(font)), textColor(fgColor), fontSize(size) {
    Texture* pTexture = Texture::makeFromText(renderTarget, fontPath, labelText, textColor, fontSize);
    texture = std::shared_ptr<Texture>(pTexture);
}

Label* Label::getInstance(SDL_Renderer* renderTarget, int x, int y, int w, int h, std::string text, std::string font, SDL_Color fgColor, int size) {
    return new Label(renderTarget, x, y, w, h, std::move(text), std::move(font), fgColor, size);
}

Label* Label::getInstance(SDL_Renderer* renderTarget, const SDL_Rect &r, std::string text, std::string font, SDL_Color fgColor, int size) {
    return new Label(renderTarget, r, std::move(text), std::move(font), fgColor, size);
}

Label* Label::getInstance(SDL_Renderer* renderTarget, int x, int y, std::string text, std::string font, SDL_Color fgColor, int size) {
    Label* tLbl = new Label(renderTarget, x, y, 0, 0, std::move(text), std::move(font), fgColor, size);
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

void Label::reloadTexture(SDL_Renderer* renderTarget) {
    texture = nullptr;
    Texture* pTexture = Texture::makeFromText(renderTarget, fontPath, labelText, textColor, fontSize);
    texture = std::shared_ptr<Texture>(pTexture);
}

void Label::update() {
}

void Label::draw(SDL_Renderer* renderTarget) const {
    texture.get()->draw(renderTarget, nullptr, &boundingRect);
}


}