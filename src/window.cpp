#define GLEW_STATIC
#include <gl/glew.h>

#include <gl/gl.h>
#include <gl/glu.h>
#include <glfw/glfw3.h>

#include <ctime>
#include <iostream>
#include <exception>

#include "window.h"

/**
 * \brief Error callback
 * \param[in] ErrorCode Error code
 * \param[in] Message Error message string
 */
VOID window::MakeError( INT ErrorCode, const CHAR *Message )
{
  throw std::runtime_error(Message);
}

/**
 * \brief Display callback
 * \param[in] Time Time for response
 */
VOID window::OnDisplay( FLT Time )
{
}

/**
 * \brief Resize framebuffer callback
 * \param[in] W Frammebuffer width
 * \param[in] H Framebuffer height
 */
VOID window::OnResizeFrame( INT W, INT H )
{
}

/**
 * \brief Resize framebuffer function
 * \param[in] Time Time for response
 */
VOID window::Display( FLT Time )
{
  OnDisplay(Time); 

  glFinish();
}

/**
 * \brief Resize framebuffer function
 * \param[in] W Frammebuffer width
 * \param[in] H Framebuffer height
 */
VOID window::ResizeFrame( INT W, INT H )
{
  FrameW = W;
  FrameH = H;

  OnResizeFrame(W, H);
}

/**
 * \brief Event loop function
 */
VOID window::Run( VOID )
{
  while (glfwWindowShouldClose(WindowPtr) != GLFW_TRUE)
  {
    FLT CurrentTime = glfwGetTime();
    FLT DeltaTime = CurrentTime - OldFPSEvaluationTime;
    
    if (DeltaTime > 1)
    {
      std::cout << "FPS: " << (NumberOfFrames / DeltaTime) << "\n";
      NumberOfFrames = 0;
      OldFPSEvaluationTime = CurrentTime;
    }

    Display(CurrentTime);
    glfwSwapBuffers(WindowPtr);
    glfwPollEvents();

    NumberOfFrames++;
  }
}

/**
 * \brief Class constructor
 * \param[in] Name Window title
 * \param[in] W Window width
 * \param[in] H Window height
 */
window::window( const std::string &Name, INT W, INT H ) : Name(Name)
{
  WindowPtr = glfwCreateWindow(W, H, Name.c_str(), nullptr, nullptr);
  
  if (WindowPtr == nullptr)
    throw std::runtime_error("Window don't created");
  
  glfwMakeContextCurrent(WindowPtr);

  glfwSetWindowUserPointer(WindowPtr, this);

  glfwSetFramebufferSizeCallback(WindowPtr, []( GLFWwindow *Wnd, INT W, INT H )
    {
      window *WindowClass = reinterpret_cast<window *>(glfwGetWindowUserPointer(Wnd));

      WindowClass->ResizeFrame(W, H);
    });

  INT NewFrameW, NewFrameH;

  glfwGetFramebufferSize(WindowPtr, &NewFrameW, &NewFrameH);
  ResizeFrame(NewFrameW, NewFrameH);

  OldFPSEvaluationTime = glfwGetTime();
}

/**
 * \brief Key pressed indicator
 * \param[in] Key Key identifier
 * \return Key is pressed flag
*/
BOOL window::IsKeyPressed( INT Key ) const
{
  return glfwGetKey(WindowPtr, Key) == GLFW_PRESS;
}

/**
 * \brief Class destructor
 */
window::~window( VOID )
{
  glfwDestroyWindow(WindowPtr);
}
