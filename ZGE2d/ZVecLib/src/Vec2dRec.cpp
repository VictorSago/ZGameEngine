//
// Created by Victor Sago on 2018-02-03.
//

#include "Vec2dRec.hpp"

namespace zvectors {

const Vec2dRec Vec2dRec::ZERO = Vec2dRec{0, 0};
const Vec2dRec Vec2dRec::RIGHT = Vec2dRec{1, 0};
const Vec2dRec Vec2dRec::LEFT = Vec2dRec{-1, 0};
const Vec2dRec Vec2dRec::UP = Vec2dRec{0, 1};
const Vec2dRec Vec2dRec::DOWN = Vec2dRec{0, -1};


double Vec2dRec::angleDiffRad(Vec2dRec v1, Vec2dRec v2) {
    double len1 = v1.getMag();
    double len2 = v2.getMag();
    return (len1 != 0 && len2 != 0) ? std::acos(v1 * v2 / (len1 * len2)) : 0;
}

double Vec2dRec::angleDiffDeg(Vec2dRec v1, Vec2dRec v2) {
    double len1 = v1.getMag();
    double len2 = v2.getMag();
    return (len1 != 0 && len2 != 0) ? std::acos(v1 * v2 / (len1 * len2)) * zvectors::RAD2DEG_FACTOR : 0;
}

double Vec2dRec::rotationDiffDeg(Vec2dRec v1, Vec2dRec v2) {
    if (v1 == Vec2dRec::ZERO || v2 == Vec2dRec::ZERO) {
        return 0;
    } else {
        double angle1 = v1.getAngleRad();
        double angle2 = v2.getAngleRad();
        return (angle2 - angle1) * zvectors::RAD2DEG_FACTOR;
    }
}

double Vec2dRec::rotationDiffRad(Vec2dRec v1, Vec2dRec v2) {
    if (v1 == Vec2dRec::ZERO || v2 == Vec2dRec::ZERO) {
        return 0;
    } else {
        double angle1 = v1.getAngleRad();
        double angle2 = v2.getAngleRad();
        return angle2 - angle1;
    }
}

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

Vec2dRec Vec2dRec::getNormalized() const {
    double len = getMag();
    return Vec2dRec{x / len, y / len};
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


Vec2dRec Vec2dRec::getRotatedDeg(double deg) const {
    return getRotatedRad(zvectors::DEG2RAD(deg));
}

Vec2dRec Vec2dRec::getRotatedRad(double rad) const {
    return Vec2dRec{x * std::cos(rad) - y * std::sin(rad), x * std::sin(rad) + y * std::cos(rad)};
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
