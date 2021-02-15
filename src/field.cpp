#include <cmath>

#include "field.h"
#include "snake.h"

/**
 * \brief Field constructor
 * \param[in] W Field width
 * \param[in] H Field height
 */
field::field( INT W, INT H ) : W(W), H(H), DistrW(0, W - 1), DistrH(0, H - 1)
{
  FoodPos.SetX(DistrW(Gen));
  FoodPos.SetY(DistrH(Gen));
  ThornPos.SetX(DistrW(Gen));
  ThornPos.SetY(DistrH(Gen));
}

/**
 * \brief Move snake function
 * \param[in] HeadPos Head position
 */
VOID field::SnakeMove( const ivec2 &HeadPos )
{
  if (SnakePtr == nullptr)
    return;

  if (HeadPos.GetX() < 0 || HeadPos.GetX() >= W ||
    HeadPos.GetY() < 0 || HeadPos.GetY() >= H)
  {
    SnakePtr->Restart();
  }

  if (HeadPos == FoodPos)
  {
    SnakePtr->EatFood();
    
    do
    {
      FoodPos.SetX(DistrW(Gen));
      FoodPos.SetY(DistrH(Gen));
    } while (SnakePtr->IsInSnake(FoodPos));
  }

  if (HeadPos == ThornPos)
  {
    SnakePtr->EatThorn();
    
    do
    {
      ThornPos.SetX(DistrW(Gen));
      ThornPos.SetY(DistrH(Gen));
    } while (SnakePtr->IsInSnake(ThornPos));
  }
}

/**
 * \brief Connect snake to field
 * \param[in, out] Snake Pointer to snake
 */
VOID field::ConnectSnake( snake *Snake )
{
  SnakePtr = Snake;
}

/**
 * \brief Connect window pointer
 * \param[in, out] Window Pointer to window
*/
VOID field::ConnectWindow( game_window *Window )
{
  WindowPtr = Window;
}

/**
 * \brief Draw unit function
 */
VOID field::DrawUnit( VOID )
{
  if (WindowPtr == nullptr)
    return;

  WindowPtr->SetColor(FoodColorR, FoodColorG, FoodColorB);
  
  FLT Scale = 0.7;
  FLT HalfSizeX = Scale / FieldW;
  FLT HalfSizeY = Scale / FieldH;
  
  FLT XC = 2 * (FoodPos.GetX() + 0.5) / FieldW - 1;
  FLT YC = 2 * (FoodPos.GetY() + 0.5) / FieldH - 1;
  
  WindowPtr->DrawRectangle(XC - HalfSizeX, YC - HalfSizeY,
    XC + HalfSizeX, YC + HalfSizeY);

  FLT ThornColorR = 0;
  FLT ThornColorG = 0;
  FLT ThornColorB = 0;

  WindowPtr->SetColor(ThornColorR, ThornColorG, ThornColorB);

  XC = 2 * (ThornPos.GetX() + 0.5) / FieldW - 1;
  YC = 2 * (ThornPos.GetY() + 0.5) / FieldH - 1;
  
  WindowPtr->DrawRectangle(XC - HalfSizeX, YC - HalfSizeY,
    XC + HalfSizeX, YC + HalfSizeY);
}

/**
 * \brief Response unit function
 * \param[in] Time Time for response
 */
VOID field::ResponseUnit( FLT Time )
{
  FLT RCoef = 7;
  FLT GCoef = 13.8;
  FLT BCoef = 5.3;

  FoodColorR = fabs(sin(Time * RCoef));
  FoodColorG = fabs(sin(Time * GCoef));
  FoodColorB = fabs(sin(Time * BCoef));
}
