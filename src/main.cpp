#define GLEW_STATIC
#include <gl/glew.h>

#include <gl/gl.h>
#include <gl/glu.h>
#include <glfw/glfw3.h>

#include <fstream>

#include "game_window.h"
#include "snake.h"
#include "field.h"

/**
 * \brief Main functioin in program
 * \return Exit code(0-if success)
 */
INT main( VOID )
{
  try
  {
    glfwSetErrorCallback(window::MakeError);

    if (glfwInit() != GLFW_TRUE)
      throw std::runtime_error("GLFW not initialized");

    std::string WindowName = "Snake";
    INT WindowW = 600;
    INT WindowH = 600;

    game_window Wnd(WindowName, WindowW, WindowH);

    snake Snake(ivec2(0, 0), ivec2(1, 0));

    INT FieldSize = 15;

    field Field(FieldSize, FieldSize);

    Snake.ConnectField(&Field);
    Field.ConnectSnake(&Snake);

    Snake.ConnectWindow(&Wnd);
    Field.ConnectWindow(&Wnd);

    Wnd.AddUnit(&Snake);
    Wnd.AddUnit(&Field);

    Wnd.Run();
  }
  catch (const std::runtime_error &Error)
  {
    std::ofstream Log("log.txt");

    Log << Error.what() << std::endl;
  }

  glfwTerminate();

  return 0;
}
