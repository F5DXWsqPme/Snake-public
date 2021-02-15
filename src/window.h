#ifndef __window_h_
#define __window_h_

#include <glfw/glfw3.h>
#include <string>

#include "def.h"

/**
 * \brief Window and event loop class
 */
class window
{
private:
  /** Pointer to window */
  GLFWwindow *WindowPtr = nullptr;

  /** Framebuffer width */
  INT FrameW = 0;

  /** Framebuffer height */
  INT FrameH = 0;

  /** Window name */
  std::string Name;

  /** Frames counter */
  INT NumberOfFrames = 0;

  /** Old FPS evaluation */
  FLT OldFPSEvaluationTime = 0;

protected:
  /**
   * \brief Display callback
   * \param[in] Time Time for response
   */
  virtual VOID OnDisplay( FLT Time );

  /**
   * \brief Resize framebuffer callback
   * \param[in] W Frammebuffer width
   * \param[in] H Framebuffer height
   */
  virtual VOID OnResizeFrame( INT W, INT H );

public:
  /** Reference to framebuffer width */
  const INT &FrameWidth = FrameW;

  /** Reference to framebuffer height */
  const INT &FrameHeight = FrameH;

  /**
   * \brief Resize framebuffer function
   * \param[in] Time Time for response
   */
  VOID Display( FLT Time );

  /**
   * \brief Resize framebuffer function
   * \param[in] W Frammebuffer width
   * \param[in] H Framebuffer height
   */
  VOID ResizeFrame( INT W, INT H );

  /**
   * \brief Event loop function
   */
  VOID Run( VOID );

  /**
   * \brief Class constructor
   * \param[in] Name Window title
   * \param[in] W Window width
   * \param[in] H Window height
   */
  window( const std::string &Name, INT W, INT H );

  /**
   * \brief Key pressed indicator
   * \param[in] Key Key identifier
   * \return Key is pressed flag
  */
  BOOL IsKeyPressed( INT Key ) const;

  /**
   * \brief Removed copy function
   * \param[in] Other Other window
   */
  window( const window &Other ) = delete;

  /**
   * \brief Removed copy function
   * \param[in] Other Other window
   * \return Reference to this
   */
  window & operator=( const window &Other ) = delete;

  /**
   * \brief Class destructor
   */
  virtual ~window( VOID );

  /**
   * \brief Error callback
   * \param[in] ErrorCode Error code
   * \param[in] Message Error message string
   */
  static VOID MakeError( INT ErrorCode, const CHAR *Message );
};

#endif /* __window_h_ */
