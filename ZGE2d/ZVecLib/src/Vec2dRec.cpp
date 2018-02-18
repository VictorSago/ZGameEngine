//
// Created by Victor Sago on 2018-02-03.
//

#include "Vec2dRec.hpp"

namespace zvectors {

void Vec2dRec::setMag(double newMag) {
    double val = newMag < 0 ? -newMag : newMag;
    scale(val/getMag());
}

void Vec2dRec::setAngleDeg(double deg) {
    double len = getMag();
    double ang = DEG2RAD(deg);
    x = len * std::cos(ang);
    y = len * std::sin(ang);
}

void Vec2dRec::setAngleRad(double rad) {
    double len = getMag();
    x = len * std::cos(rad);
    y = len * std::sin(rad);
}

void Vec2dRec::normalize() {
    double len = getMag();
    x = x / len;
    y = y / len;
}

void Vec2dRec::rotateDeg(double deg) {
    rotateRad(zvectors::DEG2RAD(deg));
}

void Vec2dRec::rotateRad(double rad) {
    double newX = x * std::cos(rad) - y * std::sin(rad);
    double newY = x * std::sin(rad) + y * std::cos(rad);
    x = newX;
    y = newY;
}

Vec2dRec Vec2dRec::operator+(const Vec2dRec& rhs) const {
    return Vec2dRec{this->x + rhs.x, this->y + rhs.y};
}

Vec2dRec Vec2dRec::operator-(const Vec2dRec& rhs) const {
    return Vec2dRec{this->x - rhs.x, this->y - rhs.y};
}

double Vec2dRec::operator*(Vec2dRec rhs) {
    return this->x * rhs.x + this->y * rhs.y;
}

}