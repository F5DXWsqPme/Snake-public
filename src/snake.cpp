#include "snake.h"
#include "field.h"

/**
 * \brief Cell constructor
 * \param[in] Pos Cell position
 * \param[in] Speed Cell speed
 */
snake::cell::cell( const ivec2 &Pos, const ivec2 &Speed ) : Pos(Pos), Speed(Speed)
{
}

/**
 * \brief Set speed function
 * \param[in] NewSpeed New cell speed
 */
VOID snake::cell::SetSpeed( const ivec2 &NewSpeed )
{
  Speed = NewSpeed;
}

/**
 * \brief Move cell
 */
VOID snake::cell::Move( VOID )
{
  Pos += Speed;
}

/**
 * \brief Get position function
 * \return Cell position
 */
ivec2 snake::cell::GetPosition( VOID ) const
{
  return Pos;
}

/**
 * \brief Get speed function
 * \return Cell speed
 */
ivec2 snake::cell::GetSpeed( VOID ) const
{
  return Speed;
}

/**
 * \brief 
 * \param[in] Pos Snake base position
 * \param[in] Speed Snake base speed
 */
snake::snake( const ivec2 &Pos, const ivec2 &Speed ) : StartPos(Pos), StartSpeed(Speed)
{
  Body.push_back(cell(Pos, Speed));
}

/**
 * \brief Test position in snake
 * \param[in] Pos Position
 * \return Test result
 */
BOOL snake::IsInSnake( const ivec2 &Pos ) const
{
  for (const cell &Cell : Body)
    if (Pos == Cell.GetPosition())
      return TRUE;

  return FALSE;
}

/**
 * \brief Move snake
 */
VOID snake::Move( VOID )
{
  cell LastCell = Body.back();

  for (cell &Cell : Body)
    Cell.Move();

  ivec2 OldSpeed = Body.front().GetSpeed();

  for (cell &Cell : Body)
  {
    ivec2 NewSpeed = Cell.GetSpeed();

    Cell.SetSpeed(OldSpeed);

    OldSpeed = NewSpeed;
  }

  if (DoEat)
  {
    DoEat = FALSE;
    Body.push_back(LastCell);
  }

  for (UINT64 i = 1; i < Body.size(); i++)
    if (Body.front().GetPosition() == Body[i].GetPosition())
    {
      Restart();
      break;
    }

  if (FieldPtr != nullptr)
    FieldPtr->SnakeMove(Body.front().GetPosition());
}

/**
 * \brief Draw unit function
 */
VOID snake::DrawUnit( VOID )
{
  if (FieldPtr == nullptr || WindowPtr == nullptr)
    return;

  FLT R = 0.6;
  FLT G = 0.6;
  FLT B = 1;

  WindowPtr->SetColor(R, G, B);

  FLT Scale = 0.7;
  FLT HalfSizeX = Scale / FieldPtr->FieldW;
  FLT HalfSizeY = Scale / FieldPtr->FieldH;

  for (const cell &Cell : Body)
  {
    ivec2 Pos = Cell.GetPosition();

    FLT XC = 2 * (Pos.GetX() + 0.5) / FieldPtr->FieldW - 1;
    FLT YC = 2 * (Pos.GetY() + 0.5) / FieldPtr->FieldH - 1;

    WindowPtr->DrawRectangle(XC - HalfSizeX, YC - HalfSizeY,
      XC + HalfSizeX, YC + HalfSizeY);
  }
}

/**
 * \brief Response unit function
 * \param[in] Time Time for response
 */
VOID snake::ResponseUnit( FLT Time )
{
  if (WindowPtr != nullptr)
  {
    if (WindowPtr->IsKeyPressed(GLFW_KEY_UP))
      Body.front().SetSpeed(ivec2(0, 1));
    if (WindowPtr->IsKeyPressed(GLFW_KEY_DOWN))
      Body.front().SetSpeed(ivec2(0, -1));
    if (WindowPtr->IsKeyPressed(GLFW_KEY_RIGHT))
      Body.front().SetSpeed(ivec2(1, 0));
    if (WindowPtr->IsKeyPressed(GLFW_KEY_LEFT))
      Body.front().SetSpeed(ivec2(-1, 0));
  }

  while (Time - OldMoveTime > MoveDelay)
  {
    OldMoveTime += MoveDelay;
    Move();
  }
}

/**
 * \brief Connect field pointer
 * \param[in, out] Field Pointer to field
*/
VOID snake::ConnectField( field *Field )
{
  FieldPtr = Field;
}

/**
 * \brief Eat food function
 */
VOID snake::EatFood( VOID )
{
  DoEat = TRUE;
}

/**
 * \brief Restart snake
 */
VOID snake::Restart( VOID )
{
  DoEat = FALSE;

  Body.clear();
  Body.push_back(cell(StartPos, StartSpeed));

  OldMoveTime = glfwGetTime();

  if (FieldPtr != nullptr)
    FieldPtr->SnakeMove(StartPos);
}

/**
 * \brief Connect window pointer
 * \param[in, out] Window Pointer to window
*/
VOID snake::ConnectWindow( game_window *Window )
{
  WindowPtr = Window;
}

/**
 * \brief Eat thorn function
 */
VOID snake::EatThorn( VOID )
{
  Body.pop_back();

  if (Body.empty())
    Restart();
}
