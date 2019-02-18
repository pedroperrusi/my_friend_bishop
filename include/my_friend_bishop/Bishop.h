/**
 * @file chess_board.h
 * @author Pedro Henrique S. Perrusi (pedro.perrusi@gmail.com)
 * @brief Chess board definition
 * @version 1.0
 * @date 2019-02-10
 * 
 * @copyright Copyright (c) 2019 Pedro Henrique S. Perrusi
 * 
 */
#ifndef _BISHOP_H_
#define _BISHOP_H_

#include <iostream>
#include <string>

namespace chess
{
const size_t CHESS_BOARD_WIDTH = 8;
const size_t CHESS_BOARD_HIGHT = 8;
/**
 * @brief Class representing our friend Bishop
 * 
 */
class Bishop
{
  public:
    // Class constructor
    Bishop()
    {
        x_pos = 0;
        y_pos = 0;
        idx_pos = 0;
    };
    // set initial 2D position on constructor
    Bishop(size_t x_pos, size_t y_pos)
    {
        setX(x_pos);
        setY(y_pos);
        setIdxFromXY();
    };
    // Class destructor
    ~Bishop()
    {
        
    };

    inline size_t getX(){ return x_pos; };

    inline void setX(size_t x_pos){ this->x_pos = x_pos; }

    inline size_t getY(){ return y_pos; };

    inline void setY(size_t y_pos){ this->y_pos = y_pos; }

    inline size_t getIdx(){ return idx_pos; };

    inline void setIdx(size_t idx_pos){ this->idx_pos = idx_pos; }

private:
    /**
     * Coordinates for a chess piece in different representations
     */
    // X position in a 2D grid
    size_t x_pos;
    // Y position in a 2D grid
    size_t y_pos;
    // index position in a 1D vector
    size_t idx_pos;

    /**
     * @brief Set the Idx From 2D X and Y coordibates
     * 
     */
    inline void setIdxFromXY()
    {
        idx_pos = x_pos + y_pos;
    }
};
} // namespace chess
#endif // _BISHOP_H_