cmake_minimum_required(VERSION 3.6.0)
project(opengl-sandbox)

set(CMAKE_CXX_STANDARD 11)

if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -pthread")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(externals)

find_package(OpenGL REQUIRED)

add_subdirectory(src)

