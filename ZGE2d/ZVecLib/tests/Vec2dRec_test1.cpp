//
// Created by Victor Sago on 2018-02-03.
//

#define BOOST_TEST_MODULE Vec2dTest
//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "Vec2dRec.hpp"

BOOST_AUTO_TEST_SUITE(Vec2dConstructorsTest)

BOOST_AUTO_TEST_CASE(DefaultVec2dRecConstructor) {
    std::cout << "Testing default constructor." << std::endl;
    zvectors::Vec2dRec v0{};
    BOOST_CHECK_MESSAGE(v0.getX() == 0 && v0.getY() == 0,
                        "Coordinates not equal to 0: (" << v0.getX() << ", " << v0.getY() << ")");
    BOOST_CHECK_MESSAGE(v0.getMag() == 0,
                        "Length not equal to 0: " << v0.getMag());
}

BOOST_AUTO_TEST_CASE(ValuedVec2dRecConst1Q) {
    std::cout << "Testing constructor - 1." << std::endl;
    zvectors::Vec2dRec v1{1, 1};
    BOOST_CHECK_MESSAGE(v1.getX() == 1 && v1.getY() == 1,
                        "Coordinates not equal to 1: (" << v1.getX() << ", " << v1.getY() << ")");
    double sqr2 = std::sqrt(2.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    BOOST_CHECK_MESSAGE(v1.getMag() == sqr2,
                        "Length not equal to sqrt(2): " << v1.getMag());
//    BOOST_CHECK_MESSAGE(v1.getAngleDeg() == 45,
//                        "Angle(Deg) not equal to 45: " << v1.getAngleDeg());
//    BOOST_CHECK_MESSAGE(v1.getAngleRad() == p_4,
//                        "Angle(Rad) not equal to Pi/4: " << v1.getAngleRad());
}

BOOST_AUTO_TEST_CASE(ValuedVec2dRecConst2Q) {
    std::cout << "Testing constructor - 2." << std::endl;
    zvectors::Vec2dRec v2{-1, 1};
    BOOST_CHECK_MESSAGE(v2.getX() == -1 && v2.getY() == 1,
                        "Coordinates not equal to 1: (" << v2.getX() << ", " << v2.getY() << ")");
    double sqr2 = std::sqrt(2.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    BOOST_CHECK_MESSAGE(v2.getMag() == sqr2,
                        "Length not equal to sqrt(2): " << v2.getMag());
//    BOOST_CHECK_MESSAGE(v2.getAngleDeg() == 135,
//                        "Angle(Deg) not equal to 135: " << v2.getAngleDeg());
//    BOOST_CHECK_MESSAGE(v2.getAngleRad() == 3*p_4,
//                        "Angle(Rad) not equal to 3Pi/4: " << v2.getAngleRad());
}

BOOST_AUTO_TEST_CASE(ValuedVec2dRecConst3Q) {
    std::cout << "Testing constructor - 3." << std::endl;
    zvectors::Vec2dRec v3{-1, -1};
    BOOST_CHECK_MESSAGE(v3.getX() == -1 && v3.getY() == -1,
                        "Coordinates not equal to 1: (" << v3.getX() << ", " << v3.getY() << ")");
    double sqr2 = std::sqrt(2.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    BOOST_CHECK_MESSAGE(v3.getMag() == sqr2,
                        "Length not equal to sqrt(2): " << v3.getMag());
//    BOOST_CHECK_MESSAGE(v3.getAngleDeg() == 225,
//                        "Angle(Deg) not equal to 225: " << v3.getAngleDeg());
//    BOOST_CHECK_MESSAGE(v3.getAngleRad() == 5*p_4,
//                        "Angle(Rad) not equal to 5Pi/4: " << v3.getAngleRad());
}

BOOST_AUTO_TEST_CASE(ValuedVec2dRecConst4Q) {
    std::cout << "Testing constructor - 4." << std::endl;
    zvectors::Vec2dRec v4{1, -1};
    BOOST_CHECK_MESSAGE(v4.getX() == 1 && v4.getY() == -1,
                        "Coordinates not equal to 1: (" << v4.getX() << ", " << v4.getY() << ")");
    double sqr2 = std::sqrt(2.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    BOOST_CHECK_MESSAGE(v4.getMag() == sqr2,
                        "Length not equal to sqrt(2): " << v4.getMag());
//    BOOST_CHECK_MESSAGE(v4.getAngleDeg() == 315,
//                        "Angle(Deg) not equal to 315: " << v4.getAngleDeg());
//    BOOST_CHECK_MESSAGE(v4.getAngleRad() == 7*p_4,
//                        "Angle(Rad) not equal to 7Pi/4: " << v4.getAngleRad());
}

BOOST_AUTO_TEST_SUITE_END()
