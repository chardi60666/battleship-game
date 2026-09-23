#include <gtest/gtest.h>
#include "GameField.h"
TEST(FieldTest, Basic) {
    GameField f; EXPECT_TRUE(f.is_valid());
}