//
// Created by Victor Sago on 2018-02-03.
//

#ifndef ZVECLIB_VEC2DREC_HPP
#define ZVECLIB_VEC2DREC_HPP

#include <cmath>

#include "Common.hpp"

namespace zvectors {

class Vec2dRec {
    protected:
        double x, y;            // Rectangular coordinates

    public:
        Vec2dRec() : x(0.0d), y(0.0d) {}
        Vec2dRec(const double& x, const double& y) : x(x), y(y) {}
        Vec2dRec(const double& x1, const double& y1, const double& x2, const double y2) : x(x2-x1), y(y2-y1) {}

//        Vec2dRec(const Vec2dRec& vec);

        inline double getX() const { return x; }
        inline double getY() const { return y; }

        inline void setX(double newX) { x = newX; }
        inline void setY(double newY) { y = newY; }
        inline void setXY(double newX, double newY) { x = newX; y = newY; }

        double getMag() const;
        double getAngleDeg() const;
        double getAngleRad() const;

        void setMag(double newMag);
        void setAngleDeg(double deg);
        void setAngleRad(double rad);

        // In-place transformations
        void normalize();                           // This vector into a unit vector
        void scale(const double& s);                // Scale this vector by factor s
        void rotateDeg(double deg);                 // Rotate this vector by deg degrees
        void rotateRad(double rad);                 // Rotate this vector by rad radians
        void reverse();                             // Reverse this vector

        Vec2dRec getNormalized() const;             // Get a new unit vector with the same direction as this vector
        Vec2dRec getScaled(const double& s) const;  // Get a new scaled vector from this vector
        Vec2dRec getRotatedDeg(double deg) const;   // Get a new vector from this one rotated deg degrees
        Vec2dRec getRotatedRad(double rad) const;   // Get a new vector from this one rotated rad radians
        Vec2dRec getReversed() const;               // Get a new vector from this one with opposite direction

        double dot(const Vec2dRec& v2) const;       // Scalar product

        // Operators
        inline bool operator==(const Vec2dRec& rhs) const { return x == rhs.x && y == rhs.y; }
        inline bool operator!=(const Vec2dRec& rhs) const { return x != rhs.x || y != rhs.y; }

        Vec2dRec operator-() const;
        Vec2dRec operator+(const Vec2dRec& rhs) const;
        Vec2dRec operator-(const Vec2dRec& rhs) const;
        double operator*(Vec2dRec rhs);
};

inline
double Vec2dRec::getMag() const {
    return std::sqrt(x*x + y*y);
}

inline
double Vec2dRec::getAngleDeg() const {
    return RAD2DEG(atan2(y, x));
}

inline
double Vec2dRec::getAngleRad() const {
    return atan2(y, x);
}

inline
void Vec2dRec::scale(const double& s) {
    x *= s;
    y *= s;
}

inline
void Vec2dRec::reverse() {
    scale(-1);
}

inline
Vec2dRec Vec2dRec::getScaled(const double& s) const {
    return Vec2dRec{x * s, y * s};
}

inline
Vec2dRec Vec2dRec::getReversed() const {
    return Vec2dRec{-x, -y};
}

inline
double Vec2dRec::dot(const Vec2dRec& v2) const {
    return x*v2.x + y*v2.y;
}

inline
Vec2dRec Vec2dRec::operator-() const {
    return Vec2dRec{-x, -y};
}

}

#endif //ZVECLIB_VEC2DREC_HPP
