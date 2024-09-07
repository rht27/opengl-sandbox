#include <iostream>

#include <GLFW/glfw3.h>

static const int WIN_WIDTH = 640;
static const int WIN_HEIGHT = 480;
static const char *WIN_TITLE = "OpenGL sandbox";

void initializeGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

int main(int argc, char **argv) {
  if (glfwInit() == GLFW_FALSE) {
    std::cerr << "Initilization failed!" << std::endl;
    return 1;
  }

  GLFWwindow *window =
      glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, NULL, NULL);
  if (window == NULL) {
    std::cerr << "Window creation failed!" << std::endl;
    glfwTerminate();
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

