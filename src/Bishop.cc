/**
 * @file Bishop.cc
 * @author Pedro Henrique S. Perrusi (pedro.perrusi@gmail.com)
 * @brief Source Bishop object definitions
 * @version 1.0
 * @date 2019-02-10
 * 
 * @copyright Copyright (c) 2019 Pedro Henrique S. Perrusi
 * 
 */
#include "my_friend_bishop/Bishop.h"

#include <iostream>

namespace chess
{

/**
 * @brief Verify wheather a position is reachable for the bishop
 * 
 * We can compare the parity between the initial and final position indexes.
 * For the first row (0), if initial index and final index have the same parity, they're reachable.
 * If the difference of rows is odd, the relation inverses itself.
 * 
 * @param x_final 
 * @param y_final 
 * @return reachable : true when x and y are reachable from the initial position
 */
bool Bishop::canGetTo(size_t x_final, size_t y_final)
{
    // output variable
    bool reachable; // useful for the inversing relations
    size_t idx_final = idxFromXY(x_final, y_final);
    if (idx_final % 2 == idx_pos % 2)
    {
        reachable = true;
    }
    else
    {
        reachable = false;
    }
    // if we're on an odd collumn, reverse the relation
    size_t y_diff = y_pos - y_final;
    if (y_diff % 2 == 1)
    {
        reachable = !reachable;
    }
    return reachable;
}

/**
 * @brief Determines how many bishop moves are necessary to go ftom the bishop position to a final possition.
 * 
 * The possible outputs are:
 *      - -1: when the final point is not reachable from the starting point
 *      - 0: when the starting point is the final point
 *      - 1: when the final point is in one of the diagonals of the starting point
 *      - 2: any other case when the point is reachable but not directly. It will taky the bishop two moves to get there 
 * 
 * @param x_final 
 * @param y_final 
 * @return int
 */
int Bishop::reachableInHowManySteps(size_t x_final, size_t y_final)
{
    size_t idx_final = idxFromXY(x_final, y_final);
    int diffIdx = idx_final - idx_pos;
    // if it is the same point...
    if (diffIdx == 0)
    {
        return 0;
    }
    // if the point is not reachable...
    if (canGetTo(x_final, y_final) == false)
    {
        return -1;
    }
    // So, it rests to know if it is reachable in one or two steps....
    //      if it is one step away from the north-west/south-est diagonal, the diffIdx is modulo of 9
    //      if it is one step away from the north-est/south-west diagonal (mmodulo of 7)
    if (diffIdx % 9 == 0 || diffIdx % 7 == 0)
    {
        return 1;
    }
    // in any other cases, it is reachable in two steps
    return 2;
}

} // namespace chess