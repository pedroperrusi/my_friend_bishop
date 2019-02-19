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
 * 
 * 
 * @param x_final 
 * @param y_final 
 * @return true 
 * @return false 
 */
bool Bishop::canGetTo(size_t x_final, size_t y_final)
  {
    size_t idx_final = idxFromXY(x_final, y_final);
    if(idx_final % 2 == idx_pos % 2)
    {
      return true;
    }
    return false;  
  }


} // namespace bunny_mesh