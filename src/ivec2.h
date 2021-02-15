#ifndef __ivec2_h_
#define __ivec2_h_

#include "def.h"

/**
 * \brief Integer 2D vector
 */
class ivec2
{
private:
  /** X coordinate */
  INT X = 0;

  /** Y coordinate */
  INT Y = 0;

public:
  /**
   * \brief Class default constructor
   */
  ivec2( VOID ) = default;

  /**
   * \brief Class constructor
   * \param[in] X X coordinate
   * \param[in] Y Y coordinate
  */
  ivec2( INT X, INT Y );

  /**
   * \brief Addition operator
   * \param[in] V Other vector
   * \return Result vector
   */
  ivec2 operator+( const ivec2 &V ) const;

  /**
   * \brief Substraction operator
   * \param[in] V Other vector
   * \return Result vector
   */
  ivec2 operator-( const ivec2 &V ) const;

  /**
   * \brief Addition operator
   * \param[in] V Other vector
   * \return Reference to this
   */
  ivec2 & operator+=( const ivec2 &V );

  /**
   * \brief Substraction operator
   * \param[in] V Other vector
   * \return Reference to this
   */
  ivec2 & operator-=( const ivec2 &V );

  /**
   * \brief Unary '-' operator
   * \return Result vector
   */
  ivec2 operator-( VOID ) const;

  /**
   * \brief Get X function
   * \return X coordinate
   */
  INT GetX( VOID ) const;

  /**
   * \brief Get Y function
   * \return Y coordinate
   */
  INT GetY( VOID ) const;

  /**
   * \brief Set X function
   * \param[in] NewX New X coordinate
   */
  VOID SetX( INT NewX );

  /**
   * \brief Set Y function
   * \param[in] NewY New Y coordinate
   */
  VOID SetY( INT NewY );

  /**
   * \brief Operator less
   * \param[in] V Other vector
   * \return Vector less than other
  */
  BOOL operator<( const ivec2 &V ) const;

  /**
   * \brief Operator equal
   * \param[in] V Other vector
   * \return Vectors equal
  */
  BOOL operator==( const ivec2 &V ) const;
};

#endif /* __ivec2_h_ */
