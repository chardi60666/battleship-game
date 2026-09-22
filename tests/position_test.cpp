#include <gtest/gtest.h>
#include "Position.h"
TEST(PositionTest, Basic) {
    Position p(5, 5);
    EXPECT_EQ(p.row(), 5);
}