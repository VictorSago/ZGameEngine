//
// Created by Victor Sago on 2018-02-24.
//

#include <iostream>
#include "Vec2dRec.hpp"
#include "gtest/gtest.h"
#include "VectorTransformationGTest.hpp"

namespace {

TEST_F(VectorTransformationGTest, getNormalTest) {
    std::cout << "GTest: Testing transformative constructions: normalize." << std::endl;
    std::cout << "v1 coords: (" << v1.getX() << ", " << v1.getY() << ")" << std::endl;
    std::cout << "v2 coords: (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;
    zvectors::Vec2dRec normV1 = v1.getNormalized();
    zvectors::Vec2dRec normV2 = v2.getNormalized();
    std::cout << "normV1 coords: (" << normV1.getX() << ", " << normV1.getY() << ")" << std::endl;
    std::cout << "normV2 coords: (" << normV2.getX() << ", " << normV2.getY() << ")" << std::endl;
    ASSERT_DOUBLE_EQ(1, normV1.getMag());
    ASSERT_EQ(1, normV2.getMag());
    double sqr2 = std::sqrt(2.0d);
    ASSERT_EQ(sqr2, v1.getMag());
    ASSERT_EQ(5, v2.getMag());
}

TEST_F(VectorTransformationGTest, getScaledTest) {
    std::cout << "GTest: Testing transformative constructions: scale." << std::endl;
    zvectors::Vec2dRec sV1 = v1.getScaled(-3.2);
    zvectors::Vec2dRec sV2 = v2.getScaled(1.5);
    ASSERT_DOUBLE_EQ(-3.2, sV1.getX());
    ASSERT_DOUBLE_EQ(-3.2, sV1.getY());
    ASSERT_DOUBLE_EQ(4.5, sV2.getX());
    ASSERT_DOUBLE_EQ(6, sV2.getY());
    ASSERT_DOUBLE_EQ(std::sqrt(2)*3.2, sV1.getMag());
    ASSERT_EQ(7.5, sV2.getMag());
    ASSERT_EQ(1, v1.getX());
    ASSERT_EQ(1, v1.getY());
    ASSERT_EQ(3, v2.getX());
    ASSERT_EQ(4, v2.getY());
}

TEST_F(VectorTransformationGTest, getReversedTest) {
    std::cout << "GTest: Testing transformative constructions: reverse." << std::endl;
    zvectors::Vec2dRec rV1 = v1.getReversed();
    zvectors::Vec2dRec rV2 = v2.getReversed();
    ASSERT_EQ(-1, rV1.getX());
    ASSERT_EQ(-1, rV1.getY());
    ASSERT_EQ(-3, rV2.getX());
    ASSERT_EQ(-4, rV2.getY());
    ASSERT_TRUE(v1.getMag() == rV1.getMag());
    ASSERT_TRUE(v2.getMag() == rV2.getMag());
}

TEST_F(VectorTransformationGTest, getRotatedRadTest) {
    std::cout << "GTest: Testing transformative constructions: rotation rad." << std::endl;
    zvectors::Vec2dRec rV11 = v1.getRotatedRad(zvectors::PI_D/2);
    zvectors::Vec2dRec rV21 = v2.getRotatedRad(zvectors::PI_D/2);
    std::cout << "v2 coords: (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;
    std::cout << "rV21 coords: (" << rV21.getX() << ", " << rV21.getY() << ")" << std::endl;
    ASSERT_DOUBLE_EQ(-1, rV11.getX());
    ASSERT_DOUBLE_EQ(1, rV11.getY());
    ASSERT_DOUBLE_EQ(-4, rV21.getX());
    ASSERT_DOUBLE_EQ(3, rV21.getY());
}

TEST_F(VectorTransformationGTest, getRotatedDegTest) {
    std::cout << "GTest: Testing transformative constructions: rotation deg." << std::endl;
    zvectors::Vec2dRec rV11 = v1.getRotatedDeg(45);
    zvectors::Vec2dRec rV21 = v2.getRotatedDeg(45).getRotatedDeg(45);
    std::cout << "v2 coords: (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;
    std::cout << "rV21 coords: (" << rV21.getX() << ", " << rV21.getY() << ")" << std::endl;
    ASSERT_NEAR(0, rV11.getX(), 0.000000000000001);
    ASSERT_DOUBLE_EQ(std::sqrt(2), rV11.getY());
    ASSERT_DOUBLE_EQ(-4, rV21.getX());
    ASSERT_DOUBLE_EQ(3, rV21.getY());
}

TEST_F(VectorTransformationGTest, getRotatedNegDegTest) {
    std::cout << "GTest: Testing transformative constructions: rotation deg." << std::endl;
    zvectors::Vec2dRec rV11 = v1.getRotatedDeg(-45);
    zvectors::Vec2dRec rV21 = v2.getRotatedDeg(-45).getRotatedDeg(-45);
    std::cout << "v2 coords: (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;
    std::cout << "rV21 coords: (" << rV21.getX() << ", " << rV21.getY() << ")" << std::endl;
    ASSERT_DOUBLE_EQ(std::sqrt(2), rV11.getX());
    ASSERT_NEAR(0, rV11.getY(), 0.000000000000001);
    ASSERT_DOUBLE_EQ(4, rV21.getX());
    ASSERT_DOUBLE_EQ(-3, rV21.getY());
}

}
