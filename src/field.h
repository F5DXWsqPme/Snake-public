#ifndef __field_h_
#define __field_h_

#include <random>

#include "game_unit.h"
#include "ivec2.h"
#include "game_window.h"

class snake;

/**
 * \brief Field class
 */
class field final : public game_unit
{
private:
  /** Field width */
  INT W;

  /** Field height */
  INT H;

  /** Food position */
  ivec2 FoodPos;

  /** Thorn position */
  ivec2 ThornPos;

  /** Pointer to snake */
  snake *SnakePtr = nullptr;

  /** Pointer to game window */
  game_window *WindowPtr = nullptr;

  /** Random numbers generator */
  std::mt19937_64 Gen;

  /** Distribution between 0 and W - 1 */
  std::uniform_int_distribution<INT> DistrW;

  /** Distribution between 0 and H - 1 */
  std::uniform_int_distribution<INT> DistrH;\

  /** Food color red part */
  FLT FoodColorR = 1;

  /** Food color red part */
  FLT FoodColorG = 0;

  /** Food color blue part */
  FLT FoodColorB = 1;

public:
  /** Reference to width */
  const INT &FieldW = W;

  /** Reference to height */
  const INT &FieldH = H;

  /**
   * \brief Field constructor
   * \param[in] W Field width
   * \param[in] H Field height
   */
  field( INT W, INT H );

  /**
   * \brief Move snake function
   * \param[in] HeadPos Head position
   */
  VOID SnakeMove( const ivec2 &HeadPos );

  /**
   * \brief Connect snake to field
   * \param[in, out] Snake Pointer to snake
   */
  VOID ConnectSnake( snake *Snake );

  /**
   * \brief Connect window pointer
   * \param[in, out] Window Pointer to window
  */
  VOID ConnectWindow( game_window *Window );

  /**
   * \brief Draw unit function
   */
  VOID DrawUnit( VOID ) override final;

  /**
   * \brief Response unit function
   * \param[in] Time Time for response
   */
  VOID ResponseUnit( FLT Time ) override final;
};

#endif /* __field_h_ */
