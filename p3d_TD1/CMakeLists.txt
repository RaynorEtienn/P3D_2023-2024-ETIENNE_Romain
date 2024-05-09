cmake_policy(SET CMP0048 NEW)

project(p3d_td1 VERSION 2021.4)

cmake_minimum_required(VERSION 2.8)

include("CMakeConfig.txt")

add_subdirectory(ext/glfw)
add_subdirectory(ext/glbinding)

include_directories(ext/glfw/include)
include_directories(ext/glbinding/include)
include_directories(ext/eigen3)

add_definitions(-DEIGEN_DONT_ALIGN_STATICALLY)

set(SRC_FILES 
    src/main.cpp
    src/viewer.cpp
    src/viewer.h
    src/shader.cpp
    src/shader.h
    src/opengl.h)

add_definitions(-DDATA_DIR="${PROJECT_SOURCE_DIR}/data")

add_executable(p3d_td1 ${SRC_FILES})

target_link_libraries(p3d_td1 glfw ${GLFW_LIBRARIES} glbinding)
