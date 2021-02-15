#ifndef __game_window_h_
#define __game_window_h_

#include <vector>

#include "window.h"
#include "game_unit.h"

/**
 * \brief Game window class
 */
class game_window final : public window
{
private:
  /** Left border of main rectangle */
  FLT LeftBorder = -1;

  /** Right border of main rectangle */
  FLT RightBorder = 1;

  /** Lower border of main rectangle */
  FLT LowerBorder = -1;

  /** Upper border of main rectangle */
  FLT UpperBorder = 1;

  /** X rectangle scale */
  FLT SizeX = 1;

  /** Y rectangle scale */
  FLT SizeY = 1;

  /** Game units */
  std::vector<game_unit *> Units;

  /**
   * \brief Display callback
   * \param[in] Time Time for response
   */
  VOID OnDisplay( FLT Time ) override final;

  /**
   * \brief Resize framebuffer callback
   * \param[in] W Frammebuffer width
   * \param[in] H Framebuffer height
   */
  VOID OnResizeFrame( INT W, INT H ) override final;

public:
  /**
   * \brief Class constructor
   * \param[in] Name Window title
   * \param[in] W Window width
   * \param[in] H Window height
   */
  game_window( const std::string &Name, INT W, INT H );

  /**
   * \brief Draw rectangle in display rectangle
   * \param[in] X0 Left border
   * \param[in] Y0 Lower border
   * \param[in] X1 Right border
   * \param[in] Y1 Upper border
   */
  VOID DrawRectangle( FLT X0, FLT Y0, FLT X1, FLT Y1 ) const;

  /**
   * \brief Set color function
   * \param[in] R Red
   * \param[in] G Green
   * \param[in] B Blue
   */
  VOID SetColor( FLT R, FLT G, FLT B ) const;

  /**
   * \brief Add unit for control
   * \param[in, out] Unit Game unit
   */
  VOID AddUnit( game_unit *Unit );
};

#endif /* __game_window_h_ */
