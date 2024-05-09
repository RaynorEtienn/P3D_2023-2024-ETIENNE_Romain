cmake_policy(SET CMP0048 NEW)

project(project VERSION 2021.1)

cmake_minimum_required(VERSION 3.2.0)

add_subdirectory(ext/glfw)
add_subdirectory(ext/glbinding)
add_subdirectory(ext/SOIL)

include_directories(ext/glfw/include)
include_directories(ext/glbinding/include)
include_directories(ext/eigen3)
include_directories(ext/SOIL/src)

if(APPLE)
  # Compile in C++11 mode
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(SRC_FILES 
    src/main.cpp
    src/viewer.cpp
    src/viewer.h
    src/shader.cpp
    src/shader.h
    src/opengl.h
    src/shape.h
    src/sphere.h
    src/sphere.cpp
    src/camera.h
    src/camera.cpp
    src/trackball.cpp
    src/trackball.h
    src/cube.cpp
    src/cube.h
)

add_definitions(-DDATA_DIR="${PROJECT_SOURCE_DIR}/data")

add_executable(projet ${SRC_FILES})

target_link_libraries(projet glfw ${GLFW_LIBRARIES} glbinding SOIL)
