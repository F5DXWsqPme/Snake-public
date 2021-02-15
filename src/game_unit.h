#ifndef __game_unit_h_
#define __game_unit_h_

#include "def.h"

/**
 * \brief Game unit interface
 */
class game_unit
{
public:
  /**
   * \brief Draw unit function
   */
  virtual VOID DrawUnit( VOID );

  /**
   * \brief Response unit function
   * \param[in] Time Time for response
   */
  virtual VOID ResponseUnit( FLT Time );

  /**
   * \brief Unit destructor
   */
  virtual ~game_unit( VOID );
};

#endif /* __game_unit_h_ */
