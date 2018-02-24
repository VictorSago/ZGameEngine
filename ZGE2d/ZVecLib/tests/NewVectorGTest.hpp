//
// Created by Victor Sago on 2018-02-24.
//

#ifndef ZGAMEENGINE2D_NEWVECTORGTEST_HPP
#define ZGAMEENGINE2D_NEWVECTORGTEST_HPP

#include <Vec2dRec.hpp>
#include <gtest/gtest.h>

namespace {

class NewVectorGTest : public ::testing::Test {
    protected:
        zvectors::Vec2dRec v1{1, 1};
        zvectors::Vec2dRec v2{3, 4};
};

}

#endif //ZGAMEENGINE2D_NEWVECTORGTEST_HPP
