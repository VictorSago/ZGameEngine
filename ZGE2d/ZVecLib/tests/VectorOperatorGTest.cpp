//
// Created by Victor Sago on 2018-03-04.
//

#include <iostream>
#include "Vec2dRec.hpp"
#include "gtest/gtest.h"
#include "VectorOperatorGTest.hpp"

namespace {

TEST_F(VectorOperatorGTest, eqalityOperators) {
    ASSERT_FALSE(vec1 == vec3);
    ASSERT_TRUE(vec1 != vec3);
    ASSERT_TRUE(vec2 != vec4);
}

TEST_F(VectorOperatorGTest, unaryMinus) {
    std::cout << "GTest: Testing transformative constructions: unary minus operator." << std::endl;
    zvectors::Vec2dRec newV0 = -vec0;
    zvectors::Vec2dRec newV1 = -vec1;
    zvectors::Vec2dRec newV3 = -vec3;
    ASSERT_EQ(-1, newV1.getX());
    ASSERT_EQ(-1, newV1.getY());
    ASSERT_EQ(-3, newV3.getX());
    ASSERT_EQ(-4, newV3.getY());
    ASSERT_TRUE(vec1.getMag() == newV1.getMag());
    ASSERT_TRUE(vec3.getMag() == newV3.getMag());
    ASSERT_EQ(0, newV0.getX());
    ASSERT_EQ(0, newV0.getY());
}

TEST_F(VectorOperatorGTest, multiplyByScalar) {
    std::cout << "GTest: Testing multiplication by scalar." << std::endl;
    double multiplier1 = 3.0;
    zvectors::Vec2dRec vec0s = vec0*multiplier1;
    zvectors::Vec2dRec vec1s = vec1*multiplier1;
    zvectors::Vec2dRec vec2s = vec2*multiplier1;
    zvectors::Vec2dRec vec3s = vec3*multiplier1;
    zvectors::Vec2dRec vec4s = vec4*multiplier1;
    ASSERT_EQ(0, vec0s.getX());
    ASSERT_EQ(0, vec0s.getY());
    ASSERT_EQ(0, vec0s.getMag());
    ASSERT_EQ(3, vec1s.getX());
    ASSERT_EQ(3, vec1s.getY());
    ASSERT_EQ(-3, vec2s.getX());
    ASSERT_EQ(3, vec2s.getY());
    ASSERT_EQ(9, vec3s.getX());
    ASSERT_EQ(12, vec3s.getY());
    ASSERT_EQ(-15, vec4s.getX());
    ASSERT_EQ(0, vec4s.getY());
}

}
