cmake_minimum_required(VERSION 3.7)
project(ruchasengine)

set(CMAKE_CXX_STANDARD 14)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

set(SOURCE_FILES ruchas-core/window.cpp ruchas-core/window.h)
add_executable(ruchasengine ${SOURCE_FILES})
target_link_libraries(ruchasengine glfw)
