//
// Created by Victor Sago on 2018-03-05.
//

#include <iostream>
#include "Vec2dRec.hpp"
#include "Common.hpp"
#include "gtest/gtest.h"
#include "VectorStaticOperationsGTest.hpp"

namespace {

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoZeroVecs) {
    std::cout << "GTest: Testing angle between vectors1.\n";
    ASSERT_DOUBLE_EQ(0, zvectors::Vec2dRec::angleDiffRad(vec0, vec0));
}

TEST_F(VectorStaticOperationsGTest, angleBetweenZeroVecAndVec11) {
    std::cout << "GTest: Testing angle between vectors2.\n";
    ASSERT_DOUBLE_EQ(0, zvectors::Vec2dRec::angleDiffRad(vec0, vec11));
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs1111) {
    std::cout << "GTest: Testing angle between vectors3.\n";
    ASSERT_NEAR(0, zvectors::Vec2dRec::angleDiffRad(vec11, vec11), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs1112) {
    std::cout << "GTest: Testing angle between vectors4.\n";
    ASSERT_DOUBLE_EQ(zvectors::PI_D/2, zvectors::Vec2dRec::angleDiffRad(vec11, vec12));
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs1113) {
    std::cout << "GTest: Testing angle between vectors5.\n";
    ASSERT_NEAR(zvectors::PI_D, zvectors::Vec2dRec::angleDiffRad(vec11, vec13), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs1311) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D, zvectors::Vec2dRec::angleDiffRad(vec13, vec11), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs111p) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D/4, zvectors::Vec2dRec::angleDiffRad(vec11, vec1p), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs111n) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D*3/4, zvectors::Vec2dRec::angleDiffRad(vec11, vec1n), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs2p14) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D*3/4, zvectors::Vec2dRec::angleDiffRad(vec2p, vec14), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs1p30deg) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D/6, zvectors::Vec2dRec::angleDiffRad(vec1p, vec30deg), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs60deg30deg) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D/6, zvectors::Vec2dRec::angleDiffRad(vec60deg, vec30deg), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs30deg60deg) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(zvectors::PI_D/6, zvectors::Vec2dRec::angleDiffRad(vec30deg, vec60deg), 0.0000001);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs1p240deg) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_DOUBLE_EQ(120, zvectors::Vec2dRec::angleDiffDeg(vec1p, vec240deg));
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs2p30Ndeg) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_DOUBLE_EQ(120, zvectors::Vec2dRec::angleDiffDeg(vec2p, vec30Ndeg));
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs2n31) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(90+53.130102354, zvectors::Vec2dRec::angleDiffDeg(vec2n, vec31), 0.0000000002);
}

TEST_F(VectorStaticOperationsGTest, angleBetweenTwoVecs30deg32) {
    std::cout << "GTest: Testing angle between vectors.\n";
    ASSERT_NEAR(180-30-57.9946167919, zvectors::Vec2dRec::angleDiffDeg(vec30deg, vec32), 0.0000000002);
}

TEST_F(VectorStaticOperationsGTest, rotationDiffTwoZeroVecs) {
    std::cout << "GTest: Testing angle between vectors1.\n";
    ASSERT_DOUBLE_EQ(0, zvectors::Vec2dRec::rotationDiffRad(vec0, vec0));
}

TEST_F(VectorStaticOperationsGTest, rotationDiff1Zero) {
    std::cout << "GTest: Testing rotation difference of zero-vector.\n";
    ASSERT_DOUBLE_EQ(0, zvectors::Vec2dRec::rotationDiffRad(vec1p, vec0));
}

TEST_F(VectorStaticOperationsGTest, rotationDiffSameVecs) {
    std::cout << "GTest: Testing rotation difference between two identical vectors.\n";
    ASSERT_DOUBLE_EQ(0, zvectors::Vec2dRec::rotationDiffDeg(vec60deg, vec60deg));
}

TEST_F(VectorStaticOperationsGTest, rotationDiffVecs1p30deg) {
    std::cout << "GTest: Testing rotation difference between vectors.\n";
    ASSERT_DOUBLE_EQ(30, zvectors::Vec2dRec::rotationDiffDeg(vec1p, vec30deg));
}

TEST_F(VectorStaticOperationsGTest, rotationDiffVecs30deg1p) {
    std::cout << "GTest: Testing rotation difference between vectors.\n";
    ASSERT_DOUBLE_EQ(-30, zvectors::Vec2dRec::rotationDiffDeg(vec30deg, vec1p));
}

TEST_F(VectorStaticOperationsGTest, rotationDiffVecs240deg30deg) {
    std::cout << "GTest: Testing rotation difference between vectors.\n";
    ASSERT_DOUBLE_EQ(150, zvectors::Vec2dRec::rotationDiffDeg(vec240deg, vec30deg));
}

}
