#include "ivec2.h"

/**
 * \brief Class constructor
 * \param[in] X X coordinate
 * \param[in] Y Y coordinate
*/
ivec2::ivec2( INT X, INT Y ) : X(X), Y(Y)
{
}

/**
 * \brief Addition operator
 * \param[in] V Other vector
 * \return Result vector
 */
ivec2 ivec2::operator+( const ivec2 &V ) const
{
  return ivec2(X + V.X, Y + V.Y);
}

/**
 * \brief Substraction operator
 * \param[in] V Other vector
 * \return Result vector
 */
ivec2 ivec2::operator-( const ivec2 &V ) const
{
  return ivec2(X - V.X, Y - V.Y);
}

/**
 * \brief Addition operator
 * \param[in] V Other vector
 * \return Reference to this
 */
ivec2 & ivec2::operator+=( const ivec2 &V )
{
  X += V.X;
  Y += V.Y;

  return *this;
}

/**
 * \brief Substraction operator
 * \param[in] V Other vector
 * \return Reference to this
 */
ivec2 & ivec2::operator-=( const ivec2 &V )
{
  X -= V.X;
  Y += V.Y;

  return *this;
}

/**
 * \brief Unary '-' operator
 * \return Result vector
 */
ivec2 ivec2::operator-( VOID ) const
{
  return ivec2(-X, -Y);
}

/**
 * \brief Get X function
 * \return X coordinate
 */
INT ivec2::GetX( VOID ) const
{
  return X;
}

/**
 * \brief Get Y function
 * \return Y coordinate
 */
INT ivec2::GetY( VOID ) const
{
  return Y;
}

/**
 * \brief Set X function
 * \param[in] NewX New X coordinate
 */
VOID ivec2::SetX( INT NewX )
{
  X = NewX;
}

/**
 * \brief Set Y function
 * \param[in] NewY New Y coordinate
 */
VOID ivec2::SetY( INT NewY )
{
  Y = NewY;
}

BOOL ivec2::operator<( const ivec2 &V ) const
{
  if (X != V.X)
    return X < V.X;

  return Y < V.Y;
}

/**
 * \brief Operator equal
 * \param[in] V Other vector
 * \return Vectors equal
*/
BOOL ivec2::operator==( const ivec2 &V ) const
{
  return X == V.X && Y == V.Y;
}
