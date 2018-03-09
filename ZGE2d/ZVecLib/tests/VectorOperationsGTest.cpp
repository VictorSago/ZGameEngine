//
// Created by Victor Sago on 2018-03-05.
//

#include <iostream>
#include "Vec2dRec.hpp"
#include "Common.hpp"
#include "gtest/gtest.h"
#include "VectorOperationsGTest.hpp"

namespace {

TEST_F(VectorOperationsGTest, angleBetweenTwoVecs) {
    std::cout << "GTest: Testing angle between vectors." << std::endl;
    ASSERT_DOUBLE_EQ(zvectors::PI_D/2, zvectors::Vec2dRec::angleDiff(vec11, vec12));
}

}
