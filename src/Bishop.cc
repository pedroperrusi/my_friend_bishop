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
 * If its an odd row, the relation inverses itself.
 * 
 * @param x_final 
 * @param y_final 
 * @return true 
 * @return false 
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
    if(y_pos % 2 == 1)
    {
        reachable = !reachable;
    }
    return reachable;
}

} // namespace chess