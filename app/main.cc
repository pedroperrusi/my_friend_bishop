/**
 * @file main.cc
 * @author Pedro Henrique S. Perrusi (pedro.perrusi@gmail.com)
 * @brief Main file for My friend Bishopproject.
 * @version 1.0
 * @date 2019-02-10
 * 
 * @copyright Copyright (c) 2019 Pedro Henrique S. Perrusi
 * 
 */
#include "my_friend_bishop/Bishop.h"

#include <iostream>
#include <string>

/**
 * @brief Main function of my_friend_bishop project
 */
int main()
{
    size_t initial_x = 3;
    size_t initial_y = 3;

    std::cout << "The considered start position is (" << initial_x << ", " << initial_y << ")" << std::endl;

    size_t final_x = 6;
    size_t final_y = 6;

    std::cout << "The considered ending position is (" << final_x << ", " << final_y << ")" << std::endl;

    chess::Bishop friendBishop(initial_x, initial_y);

    std::cout << "As expected, the position is reachable in " << friendBishop.reachableInHowManySteps(final_x, final_y) << " chess movements" << std::endl;

    return EXIT_SUCCESS;
}
