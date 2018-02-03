//
// Created by Victor Sago on 2018-02-03.
//

#ifndef ZGAMEENGINE2D_COMMON_HPP
#define ZGAMEENGINE2D_COMMON_HPP

namespace zvectors {

constexpr static double PI_D = 3.1415926535897932d;
constexpr static double RAD2DEG_FACTOR = 180.0d/PI_D;
constexpr static double DEG2RAD_FACTOR = PI_D/180.0d;
constexpr static double RAD2DEG(double rad) { return rad * RAD2DEG_FACTOR; }
constexpr static double DEG2RAD(double deg) { return deg * DEG2RAD_FACTOR; }

}

#endif //ZGAMEENGINE2D_COMMON_HPP
