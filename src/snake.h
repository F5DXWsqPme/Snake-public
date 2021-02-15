#ifndef __snake_h_
#define __snake_h_

#include <vector>
#include <glfw/glfw3.h>

#include "game_unit.h"
#include "ivec2.h"
#include "game_window.h"

class field;

/**
 * \brief Snake class
*/
class snake final : public game_unit
{
private:
  /**
   * \brief Snake cell
   */
  class cell
  {
  private:
    /** Position */
    ivec2 Pos;

    /** Speed */
    ivec2 Speed;

  public:
    /** Default cell constructor */
    cell( VOID ) = default;

    /**
     * \brief Cell constructor
     * \param[in] Pos Cell position
     * \param[in] Speed Cell speed
     */
    cell( const ivec2 &Pos, const ivec2 &Speed );

    /**
     * \brief Set speed function
     * \param[in] NewSpeed New cell speed
     */
    VOID SetSpeed( const ivec2 &NewSpeed );

    /**
     * \brief Move cell
     */
    VOID Move( VOID );

    /**
     * \brief Get position function
     * \return Cell position
     */
    ivec2 GetPosition( VOID ) const;

    /**
     * \brief Get speed function
     * \return Cell speed
     */
    ivec2 GetSpeed( VOID ) const;
  };

  /** Snake body */
  std::vector<cell> Body;

  /** Pointer to field */
  field *FieldPtr = nullptr;

  /** Pointer to game window */
  game_window *WindowPtr = nullptr;

  /** Delay between moves */
  FLT MoveDelay = 0.1;

  /** Old move time */
  FLT OldMoveTime = glfwGetTime();

  /** Eat food flag */
  BOOL DoEat = FALSE;

  /** Start position */
  ivec2 StartPos;

  /** Start speed */
  ivec2 StartSpeed;

public:
  /**
   * \brief 
   * \param[in] Pos Snake base position
   * \param[in] Speed Snake base speed
   */
  snake( const ivec2 &Pos, const ivec2 &Speed );

  /**
   * \brief Test position in snake
   * \param[in] Pos Position
   * \return Test result
   */
  BOOL IsInSnake( const ivec2 &Pos ) const;

  /**
   * \brief Move snake
   */
  VOID Move( VOID );

  /**
   * \brief Draw unit function
   */
  VOID DrawUnit( VOID ) override final;

  /**
   * \brief Response unit function
   * \param[in] Time Time for response
   */
  VOID ResponseUnit( FLT Time ) override final;

  /**
   * \brief Connect field pointer
   * \param[in, out] Field Pointer to field
  */
  VOID ConnectField( field *Field );

  /**
   * \brief Connect window pointer
   * \param[in, out] Window Pointer to window
  */
  VOID ConnectWindow( game_window *Window );

  /**
   * \brief Eat food function
   */
  VOID EatFood( VOID );

  /**
   * \brief Eat thorn function
   */
  VOID EatThorn( VOID );

  /**
   * \brief Restart snake
   */
  VOID Restart( VOID );
};

#endif /* __snake_h_ */
