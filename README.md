# Snake #
Simple snake game

### How install ###
- Install GLFW (https://www.glfw.org/)
- Install GLEW (http://glew.sourceforge.net/) 
- Install GNU GCC compiler
- Install CMake
- Install git
- git clone --recursive https://github.com/F5DXWsqPme/Snake-public
- Put next to project ext directory:
    - ext/
        - include/
            - gl/GLEW include files
            - glfw/GLFW include files
        - lib/ 
            - debug/GLEW and GLFW debug libs
            - release/GLEW and GLFW release libs
- cd Snake-public
- mkdir build
- cd build
- cmake ..
- cmake --build . (macOS: brew install gmake; gmake)
                                                                                            
