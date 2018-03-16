//
// Created by Victor Sago on 2018-03-05.
//

#ifndef ZGAMEENGINE2D_VECTOROPERATIONSGTEST_HPP
#define ZGAMEENGINE2D_VECTOROPERATIONSGTEST_HPP

#include "Vec2dRec.hpp"
#include "gtest/gtest.h"

namespace {

class VectorOperationsGTest : public ::testing::Test {
    protected:
        zvectors::Vec2dRec vec0{};
        zvectors::Vec2dRec vec1p{1, 0};
        zvectors::Vec2dRec vec1n{-1, 0};
        zvectors::Vec2dRec vec2p{0, 1};
        zvectors::Vec2dRec vec2n{0, -1};
        zvectors::Vec2dRec vec11{1, 1};
        zvectors::Vec2dRec vec12{-1, 1};
        zvectors::Vec2dRec vec13{-1, -1};
        zvectors::Vec2dRec vec14{1, -1};
        zvectors::Vec2dRec vec31{3, 4};
        zvectors::Vec2dRec vec32{-5, 8};
        zvectors::Vec2dRec vec30deg{std::sqrt(3), 1.0d};
        zvectors::Vec2dRec vec60deg{1.0d, std::sqrt(3)};
        zvectors::Vec2dRec vec30Ndeg{std::sqrt(3), -1.0d};
        zvectors::Vec2dRec vec240deg{-1.0d, std::sqrt(3)};
};

}

#endif //ZGAMEENGINE2D_VECTOROPERATIONSGTEST_HPP
