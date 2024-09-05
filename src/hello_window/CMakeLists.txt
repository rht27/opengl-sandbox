add_executable(hello_window main.cpp)

target_link_libraries(hello_window OpenGL::GL)
# target_link_libraries(hello_window OpenGL::GLU)

target_link_libraries(hello_window glfw)

