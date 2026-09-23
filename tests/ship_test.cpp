#include <gtest/gtest.h>
#include "Ship.h"
TEST(ShipTest, Basic) {
    Ship s; EXPECT_EQ(s.length, 1);
}