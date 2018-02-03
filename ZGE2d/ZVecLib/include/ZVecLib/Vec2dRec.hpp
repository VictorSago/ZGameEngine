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

        inline double getX() const { return x; }
        inline double getY() const { return y; }

        double getMag() const;
        double getAngleDeg() const;
        double getAngleRad() const;

        inline void setX(double newX) { x = newX; }
        inline void setY(double newY) { y = newY; }
        inline void setXY(double newX, double newY) { x = newX; y = newY; }
        void setMag(double newMag);
        void setAngleDeg(double deg);
        void setAngleRad(double rad);
        void setPolarDeg(double r, double adeg);
        void setPolarRad(double r, double arad);

        // In-place transformations
        void normalize();                           // This vector into a unit vector
        void scale(const double& s);                // Scale this vector by factor s
        void rotateDeg(double deg);                 // Rotate this vector by deg degrees
        void rotateRad(double rad);                 // Rotate this vector by rad radians
        void reverse();                             // Reverse this vector

        double dot(const Vec2dRec& v2) const;       // Scalar product

};

inline
double Vec2dRec::getMag() const {
    return std::sqrt(x*x + y*y);
}

}

#endif //ZVECLIB_VEC2DREC_HPP
