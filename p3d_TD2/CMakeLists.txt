cmake_policy(SET CMP0048 NEW)

project(p3d_td2 VERSION 2021.5)

cmake_minimum_required(VERSION 3.2.0)

include("CMakeConfig.txt")

add_subdirectory(ext/glfw)
add_subdirectory(ext/glbinding)

include_directories(ext/glfw/include)
include_directories(ext/glbinding/include)
include_directories(ext/eigen3)

add_definitions(-DEIGEN_DONT_ALIGN_STATICALLY)

set(SRC_FILES 
    src/camera.cpp
    src/cube.cpp
    src/main.cpp
    src/shader.cpp
    src/sphere.cpp
    src/viewer.cpp
    src/camera.h
    src/cube.h
    src/opengl.h
    src/shader.h
    src/shape.h
    src/sphere.h
    src/viewer.h
)

add_definitions(-DDATA_DIR="${PROJECT_SOURCE_DIR}/data")

add_executable(p3d_td2 ${SRC_FILES})

target_link_libraries(p3d_td2 glfw ${GLFW_LIBRARIES} glbinding)
