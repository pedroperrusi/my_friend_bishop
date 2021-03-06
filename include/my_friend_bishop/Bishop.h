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
 * @brief Set the Idx From 2D X and Y coordibates
 * 
 */
inline static size_t idxFromXY(size_t x, size_t y)
{
  size_t idx = x + y * CHESS_BOARD_WIDTH;
  return idx;
}

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
    setPosition(x_pos, y_pos);
  };
  // set initial idx vector position on constructor
  Bishop(size_t idx_pos)
  {
    setPosition(idx_pos);
  };
  // Class destructor
  ~Bishop(){

  };

  /**
   * @brief Set the Position object based on 2D coordinates
   * 
   * @param x_pos 
   * @param y_pos 
   */
  inline void setPosition(size_t x_pos, size_t y_pos)
  {
    setX(x_pos);
    setY(y_pos);
    setIdxFromXY();
  }

  /**
   * @brief Set the Position object based on vectorial coordinates
   * 
   * @param idx_pos 
   */
  inline void setPosition(size_t idx_pos)
  {
    setIdx(idx_pos);
    setXYFromIdx();
  };

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
  bool canGetTo(size_t x_final, size_t y_final);

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
  int reachableInHowManySteps(size_t x_final, size_t y_final);

  /** Get/Set methods ---------------------- */
  inline size_t getX() { return x_pos; };

  inline void setX(size_t x_pos) { this->x_pos = x_pos; }

  inline size_t getY() { return y_pos; };

  inline void setY(size_t y_pos) { this->y_pos = y_pos; }

  inline size_t getIdx() { return idx_pos; };

  inline void setIdx(size_t idx_pos) { this->idx_pos = idx_pos; }

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
    idx_pos = idxFromXY(this->x_pos, this->y_pos);
  }

  /**
     * @brief Set X and Y coordinates based on vectorial idx
     * 
     */
  inline void setXYFromIdx()
  {
    // X position is the modulo
    x_pos = idx_pos % CHESS_BOARD_WIDTH;
    // Y position is the integer division
    y_pos = idx_pos / CHESS_BOARD_WIDTH;
  }
};
} // namespace chess
#endif // _BISHOP_H_