#define GLEW_STATIC
#include <gl/glew.h>

#include <gl/gl.h>
#include <gl/glu.h>

#include "game_window.h"

/**
 * \brief Display callback
 */
VOID game_window::OnDisplay( FLT Time )
{
  for (game_unit *Unit : Units)
    Unit->ResponseUnit(Time);

  glClear(GL_COLOR_BUFFER_BIT);

  FLT R = 0.3;
  FLT G = 0.5;
  FLT B = 0.7;

  SetColor(R, G, B);
  DrawRectangle(-1, -1, 1, 1);

  for (game_unit *Unit : Units)
    Unit->DrawUnit();
}

/**
 * \brief Resize framebuffer callback
 * \param[in] W Frammebuffer width
 * \param[in] H Framebuffer height
 */
VOID game_window::OnResizeFrame( INT W, INT H )
{
  glViewport(0, 0, W, H);

  if (W > H)
  {
    UpperBorder = 1;
    LowerBorder = -1;

    FLT Ratio = H / (FLT)W;

    LeftBorder = -Ratio;
    RightBorder = Ratio;
  }
  else
  {
    RightBorder = 1;
    LeftBorder = -1;

    FLT Ratio = W / (FLT)H;

    LowerBorder = -Ratio;
    UpperBorder = Ratio;
  }

  SizeX = (RightBorder - LeftBorder) / 2;
  SizeY = (UpperBorder - LowerBorder) / 2;
}

/**
 * \brief Class constructor
 * \param[in] Name Window title
 * \param[in] W Window width
 * \param[in] H Window height
 */
game_window::game_window( const std::string &Name, INT W, INT H ) : window(Name, W, H)
{
  FLT R = 0;
  FLT G = 0;
  FLT B = 0;
  FLT A = 1;

  glClearColor(R, G, B, A);
}

/**
 * \brief Draw rectangle in display rectangle
 * \param[in] X0 Left border
 * \param[in] Y0 Lower border
 * \param[in] X1 Right border
 * \param[in] Y1 Upper border
 */
VOID game_window::DrawRectangle( FLT X0, FLT Y0, FLT X1, FLT Y1 ) const
{
  FLT CorrectedX0 = X0 * SizeX;
  FLT CorrectedY0 = Y0 * SizeY;
  FLT CorrectedX1 = X1 * SizeX;
  FLT CorrectedY1 = Y1 * SizeY;

  glRectf(CorrectedX0, CorrectedY0, CorrectedX1, CorrectedY1);
}

/**
 * \brief Set color function
 * \param[in] R Red
 * \param[in] G Green
 * \param[in] B Blue
 */
VOID game_window::SetColor( FLT R, FLT G, FLT B ) const
{
  glColor3f(R, G, B);
}

/**
 * \brief Add unit for control
 * \param[in, out] Unit Game unit
 */
VOID game_window::AddUnit( game_unit *Unit )
{
  Units.push_back(Unit);
}
