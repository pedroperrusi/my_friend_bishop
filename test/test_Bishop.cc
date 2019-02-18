/**
 * @file test_Bishop.cc
 * @brief Unitest module for the my_friend_bishop/Bishop.h file.
 * @version 1.0
 * @date 2019-02-18 
 * 
 * @copyright Copyright (c) 2019 Pedro Henrique S. Perrusi
 * 
 */
#include "gtest/gtest.h"

#include "my_friend_bishop/Bishop.h"

using namespace chess;

TEST(Bishop, default_position)
{
    Bishop friendBishop;
    ASSERT_TRUE(friendBishop.getX() == 0);
    ASSERT_TRUE(friendBishop.getY() == 0);
    ASSERT_TRUE(friendBishop.getIdx() == 0);
}

TEST(Bishop, initial_position_1_row)
{
    Bishop friendBishop(1, 0);
    ASSERT_TRUE(friendBishop.getX() == 1);
    ASSERT_TRUE(friendBishop.getY() == 0);
    ASSERT_TRUE(friendBishop.getIdx() == 1);
}

TEST(Bishop, initial_position_3_row)
{
    // 3rd row starting from 0, as C standard
    Bishop friendBishop(0, 2);
    ASSERT_TRUE(friendBishop.getX() == 0);
    ASSERT_TRUE(friendBishop.getY() == 2);
    ASSERT_TRUE(friendBishop.getIdx() == 16);
}
