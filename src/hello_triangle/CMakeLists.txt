add_executable(hello_triangle main.cpp)

target_link_libraries(hello_triangle OpenGL::GL)
# target_link_libraries(hello_window OpenGL::GLU)

target_link_libraries(hello_triangle glfw)