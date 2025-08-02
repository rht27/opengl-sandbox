add_executable(3d_transform main.cpp)
target_link_libraries(3d_transform OpenGL::GL)
target_link_libraries(3d_transform OpenGL::GLU)
target_link_libraries(3d_transform glfw)