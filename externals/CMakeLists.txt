# glm
add_subdirectory(glm)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLAD_GL "")

add_subdirectory(glfw)
# option(GLFW-CMAKE-STARTER-USE*GLFW-GLAD "Use GLAD from GLFW" ON)

# include_directories(glfw)
# include_directories("${GLFW_SOURCE_DIR}/deps")
# set(GLAD_GL "${GLFW_SOUCE_DIR}/deps/glad/gl.h")


