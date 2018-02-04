//
// Created by Victor Sago on 2018-02-03.
//

//#define BOOST_TEST_MODULE Vec2dTest
//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "Vec2dRec.hpp"

BOOST_AUTO_TEST_SUITE(Vec2dRecModificationTest)

BOOST_AUTO_TEST_CASE(Vec2dRecXYModification1_test) {
    std::cout << "Testing component modification: 1." << std::endl;
    zvectors::Vec2dRec v1{2, 1};
    v1.setX(10);
    v1.setY(-3);
    BOOST_CHECK_MESSAGE(v1.getX() == 10 && v1.getY() == -3,
                        "Coordinates of v1 incorrect: (" << v1.getX() << ", " << v1.getY() << ")");
}

BOOST_AUTO_TEST_CASE(Vec2dRecXYModification2_test) {
    std::cout << "Testing component modification: 2." << std::endl;
    zvectors::Vec2dRec v1{2, 1};
    v1.setXY(-2.7, 9.2);
    BOOST_CHECK_MESSAGE(v1.getX() == -2.7 && v1.getY() == 9.2,
                        "Coordinates of v1 incorrect: (" << v1.getX() << ", " << v1.getY() << ")");
}

BOOST_AUTO_TEST_CASE(Vec2dRecNormalize_test) {
    std::cout << "Testing component modification: normalize." << std::endl;
    zvectors::Vec2dRec v1{2, -1};
    v1.normalize();
    double len = std::sqrt(2*2 + 1);
    BOOST_CHECK_MESSAGE(v1.getX() == 2/len && v1.getY() == -1/len,
                        "Coordinates of normalized v1 incorrect: (" << v1.getX() << ", " << v1.getY() << ")");
}

BOOST_AUTO_TEST_CASE(Vec2dRecScale_test) {
    std::cout << "Testing component modification: scale." << std::endl;
    zvectors::Vec2dRec v1{2, 3};
    v1.scale(3.6);
    BOOST_CHECK_MESSAGE(v1.getX() == 7.2 && v1.getY() == 10.8,
                        "Coordinates of v1 incorrectly scaled: (" << v1.getX() << ", " << v1.getY() << ")");
}

BOOST_AUTO_TEST_CASE(Vec2dRecNormalizeAndScale_test) {
    std::cout << "Testing component modification: scale-to-length vs normalize." << std::endl;
    zvectors::Vec2dRec v1{-2, 1};
    zvectors::Vec2dRec v2{-2, 1};
    v1.scale(1/v1.getMag());
    v2.normalize();
    double len = std::sqrt(2*2 + 1);
    BOOST_CHECK_MESSAGE(v1.getX() == -2/len && v1.getY() == 1/len,
                        "Coordinates of v1 incorrect: (" << v1.getX() << ", " << v1.getY() << ")");
    BOOST_CHECK_MESSAGE(v1.getX() == v2.getX() && v1.getY() == v2.getY() && v1.getMag() == v2.getMag(),
                        "v1 unequal v2: (" << v1.getX() << ", " << v1.getY() << ") =/= (" << v2.getX() << ", " << v2.getY() << ")");
}

BOOST_AUTO_TEST_CASE(Vec2dRecSetMag1_test) {
    std::cout << "Testing component modification: new magnitude 1." << std::endl;
    zvectors::Vec2dRec v1{2, 3};
    v1.setMag(5);
    BOOST_CHECK_CLOSE(v1.getMag(), 5, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), 2.77350098, 0.0000001);
    BOOST_CHECK_CLOSE(v1.getY(), 4.16025147, 0.0000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecSetMag2_test) {
    std::cout << "Testing component modification: new magnitude 2." << std::endl;
    zvectors::Vec2dRec v1{2, 3};
    v1.setMag(-5);
    BOOST_CHECK_CLOSE(v1.getMag(), 5, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), 2.77350098, 0.0000001);
    BOOST_CHECK_CLOSE(v1.getY(), 4.16025147, 0.0000001);
}


BOOST_AUTO_TEST_CASE(Vec2dRecSetMag3_test) {
    std::cout << "Testing component modification: new magnitude 3." << std::endl;
    zvectors::Vec2dRec v1{-4, 3};
    v1.setMag(5);
    BOOST_CHECK_CLOSE(v1.getMag(), 5, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), -4, 0.0000001);
    BOOST_CHECK_CLOSE(v1.getY(), 3, 0.0000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecSetAngleDeg_test) {
    std::cout << "Testing component modification: new angle in degrees." << std::endl;
    zvectors::Vec2dRec v1{-4, 3};
    v1.setAngleDeg(-45);
    BOOST_CHECK_CLOSE(v1.getMag(), 5, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), 3.5355339, 0.000001);
    BOOST_CHECK_CLOSE(v1.getY(), -3.5355339, 0.000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecSetAngleRad_test) {
    std::cout << "Testing component modification: new angle in radians." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    v1.setAngleRad(zvectors::PI_D/6);
    BOOST_CHECK_CLOSE(v1.getMag(), 5, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), 4.330127, 0.000001);
    BOOST_CHECK_CLOSE(v1.getY(), 2.5, 0.000000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecRotateRad_test) {
    std::cout << "Testing rotation: radians." << std::endl;
    zvectors::Vec2dRec v1{3, 3};
    v1.rotateRad(zvectors::PI_D/6);
    BOOST_CHECK_CLOSE(v1.getAngleRad(), 5*zvectors::PI_D/12, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getMag(), 3*std::sqrt(2), 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), 3*std::sqrt(2) * std::cos(5*zvectors::PI_D/12), 0.000000001);
    BOOST_CHECK_CLOSE(v1.getY(), 3*std::sqrt(2) * std::sin(5*zvectors::PI_D/12), 0.000000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecRotateDeg_test) {
    std::cout << "Testing rotation: degrees." << std::endl;
    zvectors::Vec2dRec v1{2, -2};
    v1.rotateDeg(-145);
    BOOST_CHECK_CLOSE(v1.getAngleDeg(), 170, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getMag(), 2*std::sqrt(2), 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), 2*std::sqrt(2) * std::cos(zvectors::DEG2RAD(170)), 0.000000001);
    BOOST_CHECK_CLOSE(v1.getY(), 2*std::sqrt(2) * std::sin(zvectors::DEG2RAD(170)), 0.000000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecReverse_test) {
    std::cout << "Testing component modification: reverse this vector." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    v1.reverse();
    BOOST_CHECK_CLOSE(v1.getMag(), 5, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getX(), -3, 0.000000001);
    BOOST_CHECK_CLOSE(v1.getY(), 4, 0.000000001);
}

BOOST_AUTO_TEST_CASE(Vec2dRecInnerProd_test) {
    std::cout << "Testing component modification: scalar product." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    zvectors::Vec2dRec v2{5, 1.3};
    double prod = v1.dot(v2);
    BOOST_CHECK_CLOSE(prod, 9.8, 0.000000001);
}



BOOST_AUTO_TEST_SUITE_END()
