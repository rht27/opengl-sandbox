add_executable(window_resizing main.cpp)
target_link_libraries(window_resizing OpenGL::GL)
target_link_libraries(window_resizing OpenGL::GLU)
target_link_libraries(window_resizing glfw)