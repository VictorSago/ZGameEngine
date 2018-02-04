//
// Created by Victor Sago on 2018-02-03.
//

#define BOOST_TEST_MODULE Vec2dTest
//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "Vec2dRec.hpp"

BOOST_AUTO_TEST_SUITE(Vec2dRecConstructorsTest)

BOOST_AUTO_TEST_CASE(DefaultVec2dRecConstructor_test) {
    std::cout << "Testing default constructor." << std::endl;
    zvectors::Vec2dRec v0{};
    BOOST_CHECK_MESSAGE(v0.getX() == 0 && v0.getY() == 0,
                        "Coordinates not equal to 0: (" << v0.getX() << ", " << v0.getY() << ")");
    BOOST_CHECK_MESSAGE(v0.getMag() == 0,
                        "Length not equal to 0: " << v0.getMag());
}

BOOST_AUTO_TEST_CASE(ValuedVec2dRecConstructQ1to4_test) {
    std::cout << "Testing constructor: vectors in 1st, 2nd, 3rd and 4th quadrants." << std::endl;
    zvectors::Vec2dRec v1{1, 1};
    zvectors::Vec2dRec v2{-1, 1};
    zvectors::Vec2dRec v3{-1, -1};
    zvectors::Vec2dRec v4{1, -1};
    BOOST_CHECK_MESSAGE(v1.getX() == 1 && v1.getY() == 1,
                        "Coordinates of v1 incorrect: (" << v1.getX() << ", " << v1.getY() << ")");
    BOOST_CHECK_MESSAGE(v2.getX() == -1 && v2.getY() == 1,
                        "Coordinates of v2 incorrect: (" << v2.getX() << ", " << v2.getY() << ")");
    BOOST_CHECK_MESSAGE(v3.getX() == -1 && v3.getY() == -1,
                        "Coordinates of v3 incorrect: (" << v3.getX() << ", " << v3.getY() << ")");
    BOOST_CHECK_MESSAGE(v4.getX() == 1 && v4.getY() == -1,
                        "Coordinates of v4 incorrect: (" << v4.getX() << ", " << v4.getY() << ")");
    double sqr2 = std::sqrt(2.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    BOOST_CHECK_MESSAGE(v1.getMag() == sqr2,
                        "v1: Length of v1 not equal to sqrt(2): " << v1.getMag());
    BOOST_CHECK_MESSAGE(v2.getMag() == sqr2,
                        "v2: Length of v2 not equal to sqrt(2): " << v2.getMag());
    BOOST_CHECK_MESSAGE(v3.getMag() == sqr2,
                        "v3: Length of v3 not equal to sqrt(2): " << v3.getMag());
    BOOST_CHECK_MESSAGE(v4.getMag() == sqr2,
                        "v4: Length of v4 not equal to sqrt(2): " << v4.getMag());
    BOOST_CHECK_MESSAGE(v1.getAngleDeg() == 45,
                        "v1: Angle(Deg) not equal to 45: " << v1.getAngleDeg());
    BOOST_CHECK_MESSAGE(v1.getAngleRad() == p_4,
                        "v1: Angle(Rad) not equal to Pi/4: " << v1.getAngleRad());
    BOOST_CHECK_MESSAGE(v2.getAngleDeg() == 135,
                        "v2: Angle(Deg) not equal to 135: " << v2.getAngleDeg());
    BOOST_CHECK_MESSAGE(v2.getAngleRad() == 3*p_4,
                        "v2: Angle(Rad) not equal to 3Pi/4: " << v2.getAngleRad());
    BOOST_CHECK_MESSAGE(v3.getAngleDeg() == -135,
                        "v3: Angle(Deg) not equal to -135: " << v3.getAngleDeg());
    BOOST_CHECK_MESSAGE(v3.getAngleRad() == -3*p_4,
                        "v3: Angle(Rad) not equal to -3Pi/4: " << v3.getAngleRad());
    BOOST_CHECK_MESSAGE(v4.getAngleDeg() == -45,
                        "v4: Angle(Deg) not equal to -45: " << v4.getAngleDeg());
    BOOST_CHECK_MESSAGE(v4.getAngleRad() == -p_4,
                        "v4: Angle(Rad) not equal to -Pi/4: " << v4.getAngleRad());

}

BOOST_AUTO_TEST_CASE(ValuedVec2dConstructXY_test) {
    std::cout << "Testing constructor: vectors along the XY-axes." << std::endl;
    zvectors::Vec2dRec v1{1, 0};
    zvectors::Vec2dRec v2{0, 3};
    zvectors::Vec2dRec v3{-4, 0};
    zvectors::Vec2dRec v4{0, -5};
    BOOST_CHECK_MESSAGE(v1.getX() == 1 && v1.getY() == 0,
                        "Coordinates not equal to (1, 0): (" << v1.getX() << ", " << v1.getY() << ")");
    BOOST_CHECK_MESSAGE(v1.getMag() == 1,
                        "Length not equal to 1: " << v1.getMag());
    BOOST_CHECK_MESSAGE(v2.getX() == 0 && v2.getY() == 3,
                        "Coordinates not equal to (0, 3): (" << v2.getX() << ", " << v2.getY() << ")");
    BOOST_CHECK_MESSAGE(v2.getMag() == 3,
                        "Length not equal to 3: " << v2.getMag());
    BOOST_CHECK_MESSAGE(v3.getX() == -4 && v3.getY() == 0,
                        "Coordinates not equal to (-4, 0): (" << v3.getX() << ", " << v3.getY() << ")");
    BOOST_CHECK_MESSAGE(v3.getMag() == 4,
                        "Length not equal to 4: " << v3.getMag());
    BOOST_CHECK_MESSAGE(v4.getX() == 0 && v4.getY() == -5,
                        "Coordinates not equal to (0, -5): (" << v4.getX() << ", " << v4.getY() << ")");
    BOOST_CHECK_MESSAGE(v4.getMag() == 5,
                        "Length not equal to 5: " << v4.getMag());

    BOOST_CHECK_MESSAGE(v1.getAngleDeg() == 0,
                        "v1: Angle(Deg) incorrect: " << v1.getAngleDeg());
    BOOST_CHECK_MESSAGE(v1.getAngleRad() == 0,
                        "v1: Angle(Rad) incorrect: " << v1.getAngleRad());
    BOOST_CHECK_MESSAGE(v2.getAngleDeg() == 90,
                        "v2: Angle(Deg) incorrect: " << v2.getAngleDeg());
    BOOST_CHECK_MESSAGE(v2.getAngleRad() == zvectors::PI_D/2,
                        "v2: Angle(Rad) incorrect: " << v2.getAngleRad());
    BOOST_CHECK_MESSAGE(v3.getAngleDeg() == 180,
                        "v3: Angle(Deg) incorrect: " << v3.getAngleDeg());
    BOOST_CHECK_MESSAGE(v3.getAngleRad() == zvectors::PI_D,
                        "v3: Angle(Rad) incorrect: " << v3.getAngleRad());
    BOOST_CHECK_MESSAGE(v4.getAngleDeg() == -90,
                        "v4: Angle(Deg) incorrect: " << v4.getAngleDeg());
    BOOST_CHECK_MESSAGE(v4.getAngleRad() == -zvectors::PI_D/2,
                        "v4: Angle(Rad) incorrect: " << v4.getAngleRad());
}

BOOST_AUTO_TEST_CASE(ValuedVec2dConstuctArbitrary_test) {
    std::cout << "Testing constructor: arbitrary vectors in 4 quadrants." << std::endl;
    zvectors::Vec2dRec v1{2, 1};
    zvectors::Vec2dRec v2{-2, 1};
    zvectors::Vec2dRec v3{-1, -2};
    zvectors::Vec2dRec v4{1, -2};
    double sqr5 = std::sqrt(5.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    BOOST_CHECK_MESSAGE(v1.getX() == 2 && v1.getY() == 1,
                        "Coordinates of v1 not equal to (2, 1): (" << v1.getX() << ", " << v1.getY() << ")");
    BOOST_CHECK_MESSAGE(v1.getMag() == sqr5,
                        "Length of v1 incorrect: " << v1.getMag());
    BOOST_CHECK_MESSAGE(v2.getX() == -2 && v2.getY() == 1,
                        "Coordinates of v2 not equal to (-2, 1): (" << v2.getX() << ", " << v2.getY() << ")");
    BOOST_CHECK_MESSAGE(v2.getMag() == sqr5,
                        "Length of v2 incorrect: " << v2.getMag());
    BOOST_CHECK_MESSAGE(v3.getX() == -1 && v3.getY() == -2,
                        "Coordinates of v3 not equal to (-1, -2): (" << v3.getX() << ", " << v3.getY() << ")");
    BOOST_CHECK_MESSAGE(v3.getMag() == sqr5,
                        "Length of v3 incorrect: " << v3.getMag());
    BOOST_CHECK_MESSAGE(v4.getX() == 1 && v4.getY() == -2,
                        "Coordinates of v4 not equal to (1, -2): (" << v4.getX() << ", " << v4.getY() << ")");
    BOOST_CHECK_MESSAGE(v4.getMag() == sqr5,
                        "Length of v4 incorrect: " << v4.getMag());

    BOOST_CHECK_CLOSE(v1.getAngleDeg(), 26.565, 0.01);
    BOOST_CHECK_CLOSE(v1.getAngleRad(), 0.4636476, 0.001);
    BOOST_CHECK_CLOSE(v2.getAngleDeg(), 153.435, 0.01);
    BOOST_CHECK_CLOSE(v2.getAngleRad(), 2.67794504, 0.001);
    BOOST_CHECK_CLOSE(v3.getAngleDeg(), -116.565, 0.01);
    BOOST_CHECK_CLOSE(v3.getAngleRad(), -2.0344439, 0.001);
    BOOST_CHECK_CLOSE(v4.getAngleDeg(), -63.435, 0.01);
    BOOST_CHECK_CLOSE(v4.getAngleRad(), -1.1071487, 0.001);
}

BOOST_AUTO_TEST_CASE(Valued4Vec2dConstuctArbitrary_test) {
    std::cout << "Testing constructor with 4 args: arbitrary vectors." << std::endl;
    zvectors::Vec2dRec v1{2, 11, 9, 1};
    double len = std::sqrt(149.0d);
    BOOST_CHECK_MESSAGE(v1.getX() == 7 && v1.getY() == -10,
                        "Coordinates of v1 incorrect: (" << v1.getX() << ", " << v1.getY() << ")");
    BOOST_CHECK_MESSAGE(v1.getMag() == len,
                        "Length of v1 incorrect: " << v1.getMag());

    BOOST_CHECK_CLOSE(v1.getAngleDeg(), -55.008, 0.01);
    BOOST_CHECK_CLOSE(v1.getAngleRad(), -0.960076, 0.001);
}


BOOST_AUTO_TEST_SUITE_END()
