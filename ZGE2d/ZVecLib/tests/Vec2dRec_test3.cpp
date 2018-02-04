//
// Created by Victor Sago on 2018-02-03.
//

//#define BOOST_TEST_MODULE Vec2dTest
//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "Vec2dRec.hpp"

BOOST_AUTO_TEST_SUITE(Vec2dRecRelOperatorsTest)

BOOST_AUTO_TEST_CASE(Vec2RecEquals_test) {
    std::cout << "Testing equality relation." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    zvectors::Vec2dRec v2{-3, 4};
    BOOST_CHECK_MESSAGE(v1 != v2, "Vectors should be unequal.");
    v1.reverse();
    BOOST_CHECK_MESSAGE(v1 == v2, "Vectors are unequal.");
}

BOOST_AUTO_TEST_CASE(Vec2RecAddition_test) {
    std::cout << "Testing addition operation." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    zvectors::Vec2dRec v2{-5, 10};
    zvectors::Vec2dRec v3 = v1 + v2;
    BOOST_CHECK_MESSAGE(v3.getX() == -2, "X-coordinate should be -2");
    BOOST_CHECK_MESSAGE(v3.getY() == 6, "Y-coordinate should be 6");
}

BOOST_AUTO_TEST_CASE(Vec2RecSubtraction_test) {
    std::cout << "Testing subtraction operation." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    zvectors::Vec2dRec v2{-5, 10};
    zvectors::Vec2dRec v3 = v1 - v2;
    BOOST_CHECK_MESSAGE(v3.getX() == 8, "X-coordinate should be 8");
    BOOST_CHECK_MESSAGE(v3.getY() == -14, "Y-coordinate should be -14");
}

BOOST_AUTO_TEST_CASE(Vec2RecExpression1_test) {
    std::cout << "Testing a more complex expression." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    zvectors::Vec2dRec v2{-5, 10};
    zvectors::Vec2dRec v3{8.2, 2.1};
    zvectors::Vec2dRec v4{-5.6, 6.5};
    zvectors::Vec2dRec v5 = v3 + v1 - v2 + v4;
    BOOST_CHECK_MESSAGE(v5.getX() == 10.6, "X-coordinate should be 10.6");
    BOOST_CHECK_MESSAGE(v5.getY() == -5.4, "Y-coordinate should be -5.4");
}

BOOST_AUTO_TEST_CASE(Vec2RecScalarProduct_test) {
    std::cout << "Testing scalar product operation." << std::endl;
    zvectors::Vec2dRec v1{3, -4};
    zvectors::Vec2dRec v2{-5, 10};
    double prod = v1 * v2;
    BOOST_CHECK_MESSAGE(prod == -55, "The inner product of v1 and v2 should be -55");
}

BOOST_AUTO_TEST_SUITE_END()