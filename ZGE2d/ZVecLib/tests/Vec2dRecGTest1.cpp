//
// Created by Victor Sago on 2018-02-24.
//

#include <iostream>
#include "Vec2dRec.hpp"
#include "gtest/gtest.h"

namespace {

TEST(ConstructorTests, DefaultConstructorTest) {
    std::cout << "GTest: Testing default constructor." << std::endl;
    zvectors::Vec2dRec v0{};
    ASSERT_TRUE(v0.getX() == 0 && v0.getY() == 0);
    ASSERT_EQ(0, v0.getMag());
}

TEST(ConstructorTests, ValuedConstructorTest1) {
    std::cout << "GTest: Testing constructor: vectors along the XY-axes." << std::endl;
    zvectors::Vec2dRec v1{1, 0};
    zvectors::Vec2dRec v2{0, 3};
    zvectors::Vec2dRec v3{-4, 0};
    zvectors::Vec2dRec v4{0, -5};
    ASSERT_EQ(1, v1.getMag());
    ASSERT_EQ(3, v2.getMag());
    ASSERT_EQ(4, v3.getMag());
    ASSERT_EQ(5, v4.getMag());
}

TEST(ConstructorTests, ValuedConstructorTest2) {
    std::cout << "GTest: Testing constructor: vectors in 1st, 2nd, 3rd and 4th quadrants." << std::endl;
    zvectors::Vec2dRec v1{1, 1};
    zvectors::Vec2dRec v2{-1, 1};
    zvectors::Vec2dRec v3{-1, -1};
    zvectors::Vec2dRec v4{1, -1};
    double sqr2 = std::sqrt(2.0d);
    double p_4 = zvectors::PI_D / 4.0d;
    ASSERT_TRUE(v1.getX() == 1 && v1.getY() == 1);
    ASSERT_DOUBLE_EQ(sqr2, v1.getMag());
    ASSERT_DOUBLE_EQ(45, v1.getAngleDeg());
    ASSERT_DOUBLE_EQ(p_4, v1.getAngleRad());
    ASSERT_TRUE(v2.getX() == -1 && v2.getY() == 1);
    ASSERT_DOUBLE_EQ(sqr2, v2.getMag());
    ASSERT_DOUBLE_EQ(135, v2.getAngleDeg());
    ASSERT_DOUBLE_EQ(3*p_4, v2.getAngleRad());
    ASSERT_TRUE(v3.getX() == -1 && v3.getY() == -1);
    ASSERT_DOUBLE_EQ(sqr2, v3.getMag());
    ASSERT_DOUBLE_EQ(-135, v3.getAngleDeg());
    ASSERT_DOUBLE_EQ(-3*p_4, v3.getAngleRad());
    ASSERT_TRUE(v4.getX() == 1 && v4.getY() == -1);
    ASSERT_DOUBLE_EQ(sqr2, v4.getMag());
    ASSERT_DOUBLE_EQ(-45, v4.getAngleDeg());
    ASSERT_DOUBLE_EQ(-p_4, v4.getAngleRad());
}

TEST(ConstructorTests, CopyConstructor) {
    std::cout << "GTest: Testing copy constructor." << std::endl;
    zvectors::Vec2dRec v1{3, 4};
    zvectors::Vec2dRec v2(v1);
    ASSERT_TRUE(v2 == v1);
    ASSERT_EQ(5, v2.getMag());
}

TEST(ConstructorTests, AssignmentOperator) {
    std::cout << "GTest: Testing copy constructor." << std::endl;
    zvectors::Vec2dRec v1{3, 4};
    zvectors::Vec2dRec v2 = v1;
    ASSERT_TRUE(v2 == v1);
}

}
