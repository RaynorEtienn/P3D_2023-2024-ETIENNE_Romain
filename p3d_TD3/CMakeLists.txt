cmake_policy(SET CMP0048 NEW)

project(p3d_td3 VERSION 2021.1)

cmake_minimum_required(VERSION 3.2.0)

include("CMakeConfig.txt")

add_subdirectory(ext/glfw)
add_subdirectory(ext/glbinding)
add_subdirectory(ext/SOIL)

include_directories(ext/glfw/include)
include_directories(ext/glbinding/include)
include_directories(ext/eigen3)
include_directories(ext/SOIL/src)


set(SRC_FILES 
    src/main.cpp
    src/viewer.cpp
    src/viewer.h
    src/shader.cpp
    src/shader.h
    src/opengl.h
    src/shape.h
    src/cube.h
    src/cube.cpp
    src/sphere.h
    src/sphere.cpp
    src/quad.h
    src/quad.cpp
    src/camera.h
    src/camera.cpp
    src/mesh.h
    src/mesh.cpp
    src/meshloader.h
    src/meshloader.cpp
    src/trackball.cpp
    src/trackball.h
)

add_definitions(-DDATA_DIR="${PROJECT_SOURCE_DIR}/data")

add_executable(p3d_td3 ${SRC_FILES})

target_link_libraries(p3d_td3 glfw ${GLFW_LIBRARIES} glbinding SOIL)
