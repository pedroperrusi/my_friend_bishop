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
    ASSERT_EQ(friendBishop.getX(), 0);
    ASSERT_EQ(friendBishop.getY(), 0);
    ASSERT_EQ(friendBishop.getIdx(), 0);
}

TEST(Bishop, initial_position_1_row)
{
    Bishop friendBishop(1, 0);
    ASSERT_EQ(friendBishop.getX(), 1);
    ASSERT_EQ(friendBishop.getY(), 0);
    ASSERT_EQ(friendBishop.getIdx(), 1);
}

TEST(Bishop, initial_position_3_row)
{
    // 3rd row starting from 0, as C standard
    Bishop friendBishop(0, 2);
    ASSERT_EQ(friendBishop.getX(), 0);
    ASSERT_EQ(friendBishop.getY(), 2);
    ASSERT_EQ(friendBishop.getIdx(), 16);
}

TEST(Bishop, arbitrary_2D_position_to_idx)
{
    // 5th row, 2nd collumn starting from 0, as C standard
    Bishop friendBishop(1, 4);
    ASSERT_EQ(friendBishop.getX(), 1);
    ASSERT_EQ(friendBishop.getY(), 4);
    ASSERT_EQ(friendBishop.getIdx(), 33);
}

TEST(Bishop, first_row_idx_to_2d_position)
{
    // equvalent to the postion pair (x=5,y=0)
    Bishop friendBishop(5);
    ASSERT_EQ(friendBishop.getIdx(), 5);
    ASSERT_EQ(friendBishop.getX(), 5);
    ASSERT_EQ(friendBishop.getY(), 0);
}

TEST(Bishop, second_row_idx_to_2d_position)
{
    // equvalent to the postion pair (x=2,y=1)
    Bishop friendBishop(10);
    ASSERT_EQ(friendBishop.getIdx(), 10);
    ASSERT_EQ(friendBishop.getX(), 2);
    ASSERT_EQ(friendBishop.getY(), 1);
}

TEST(Bishop, trivial_a_possible_position)
{
    Bishop friendBishop(1, 2);
    ASSERT_TRUE(friendBishop.canGetTo(1,2));
}

TEST(Bishop, first_row_possible_position)
{
    Bishop friendBishop(0, 0);
    ASSERT_FALSE(friendBishop.canGetTo(1,0));
    ASSERT_TRUE(friendBishop.canGetTo(2,0));
}

TEST(Bishop, first_col_possible_position)
{
    Bishop friendBishop(0, 0);
    ASSERT_TRUE(friendBishop.canGetTo(2,0));
    ASSERT_FALSE(friendBishop.canGetTo(3,0));
}

TEST(Bishop, any_col_possible_position)
{
    Bishop friendBishop(1, 5);
    ASSERT_TRUE(friendBishop.canGetTo(3,7));
    ASSERT_FALSE(friendBishop.canGetTo(1,0));
}

TEST(Bishop, trivial_reachable_in_0_steps)
{
    Bishop friendBishop(1, 5);
    ASSERT_EQ(friendBishop.reachableInHowManySteps(1,5), 0);
}

TEST(Bishop, trivial_non_reachable_in_any_steps)
{
    Bishop friendBishop(1, 5);
    ASSERT_EQ(friendBishop.reachableInHowManySteps(2,5), -1);
}

TEST(Bishop, reachable_in_one_step)
{
    Bishop friendBishop(3, 3);
    // north-west/south-est diagonal
    ASSERT_EQ(friendBishop.reachableInHowManySteps(0,0), 1);
    ASSERT_EQ(friendBishop.reachableInHowManySteps(5,5), 1);
    // north-est/south-west diagonal
    ASSERT_EQ(friendBishop.reachableInHowManySteps(2,4), 1);
    ASSERT_EQ(friendBishop.reachableInHowManySteps(4,2), 1);
}

TEST(Bishop, reachable_in_two_steps)
{
    // 5th row, 2nd collumn starting from 0, as C standard
    Bishop friendBishop(3, 3);
    ASSERT_EQ(friendBishop.reachableInHowManySteps(5,3), 2);
    ASSERT_EQ(friendBishop.reachableInHowManySteps(1,3), 2);
}