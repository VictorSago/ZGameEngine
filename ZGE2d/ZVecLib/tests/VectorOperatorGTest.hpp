//
// Created by Victor Sago on 2018-03-04.
//

#ifndef ZGAMEENGINE2D_VECTOROPERATORGTEST_HPP
#define ZGAMEENGINE2D_VECTOROPERATORGTEST_HPP

#include "Vec2dRec.hpp"
#include "gtest/gtest.h"

namespace {

class VectorOperatorGTest : public ::testing::Test {
    protected:
        zvectors::Vec2dRec vec0{};
        zvectors::Vec2dRec vec1{1, 1};
        zvectors::Vec2dRec vec2{-1, 1};
        zvectors::Vec2dRec vec3{3, 4};
        zvectors::Vec2dRec vec4{-5, 0};
};

}

#endif //ZGAMEENGINE2D_VECTOROPERATORGTEST_HPP
