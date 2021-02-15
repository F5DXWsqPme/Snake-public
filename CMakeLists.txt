cmake_minimum_required(VERSION 3.16)

set(CURRENT_PROJECT_NAME Snake)

project(${CURRENT_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

IF(UNIX)
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)
ENDIF(UNIX)

set(PROJECT_SOURCES
  src/def.h
  src/window.h
  src/game_window.h
  src/game_unit.h
  src/snake.h
  src/ivec2.h
  src/field.h

  src/window.cpp
  src/game_window.cpp
  src/game_unit.cpp
  src/snake.cpp
  src/ivec2.cpp
  src/field.cpp)

add_executable(${CURRENT_PROJECT_NAME}
  ${PROJECT_SOURCES}
  src/main.cpp)

target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE src)
target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE ext/include)

message(${CMAKE_BUILD_TYPE})

message(${CMAKE_BUILD_TYPE})

IF (CMAKE_BUILD_TYPE MATCHES Debug)
  set(LIB_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ext/lib/debug)
ELSE (CMAKE_BUILD_TYPE MATCHES Debug)
  set(LIB_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ext/lib/release)
ENDIF (CMAKE_BUILD_TYPE MATCHES Debug)

target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE 
  ${LIB_DIRECTORY}/glew32.lib
  ${LIB_DIRECTORY}/glew32s.lib
  ${LIB_DIRECTORY}/glfw3.lib
  opengl32.lib
  glu32.lib)
