cmake_minimum_required(VERSION 3.7)
project(ruchasengine)

set(CMAKE_CXX_STANDARD 14)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
    message(Error " GLEW not found")
endif(NOT GLEW_FOUND)



find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OpenGL_FOUND)
    message(Error "OpenGL not found")
endif(NOT OpenGL_FOUND)

set(SOURCE_FILES ruchas-core/window.cpp ruchas-core/window.h)
add_executable(ruchasengine ${SOURCE_FILES})
target_link_libraries(ruchasengine ${OPENGL_LIBRARIES} glfw ${GLEW_LIBRARIES})
