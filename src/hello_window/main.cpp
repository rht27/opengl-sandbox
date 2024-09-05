#include <iostream>

#include <GLFW/glfw3.h>

static const int WIN_WIDTH = 640;
static const int WIN_HEIGHT = 480;
static const char *WIN_TITLE = "OpenGL sandbox";

void initializeGL() {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv) {
  if (glfwInit() == GLFW_FALSE) {
    fprintf(stderr, "Initilization failed!\n");
    return 1;
  }

  GLFWwindow *window =
      glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, NULL, NULL);
  if (window == NULL) {
    fprintf(stderr, "Window creation failed!\n");
    return 1;
  }

  glfwMakeContextCurrent(window);

  initializeGL();

  while (glfwWindowShouldClose(window) == GLFW_FALSE) {
    paintGL();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}
