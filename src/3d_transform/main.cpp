#include <iostream>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

static const int WIN_WIDTH = 640;
static const int WIN_HEIGHT = 480;
static const char *WIN_TITLE = "OpenGL sandbox";

static const float positions[8][3] = {
  { -1.0f, -1.0f, -1.0f },
  {  1.0f, -1.0f, -1.0f },
  { -1.0f,  1.0f, -1.0f },
  { -1.0f, -1.0f,  1.0f },
  {  1.0f,  1.0f, -1.0f },
  { -1.0f,  1.0f,  1.0f },
  {  1.0f, -1.0f,  1.0f },
  {  1.0f,  1.0f,  1.0f }
};

static const float colors[6][3] = {
  { 1.0f, 0.0f, 0.0f },
  { 0.0f, 1.0f, 0.0f },
  { 0.0f, 0.0f, 1.0f },
  { 1.0f, 1.0f, 0.0f },
  { 0.0f, 1.0f, 1.0f },
  { 1.0f, 0.0f, 1.0f }
};

static const unsigned int faces[12][3] = {
  { 7, 4, 1 }, { 7, 1, 6 },
  { 2, 4, 7 }, { 2, 7, 5 },
  { 5, 7, 6 }, { 5, 6, 3 },
  { 4, 2, 0 }, { 4, 0, 1 },
  { 3, 6, 1 }, { 3, 1, 0 },
  { 2, 5, 3 }, { 2, 3, 0 },
};

void initializeGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  glEnable(GL_DEPTH_TEST);
}

void paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

  // Viewport tansform
  glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

  // Specify projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Perspective projection
  gluPerspective(45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT, 1.0f, 10.0f);

  // Specify model-view matrix
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(
    3.0f, 4.0f, 5.0f,  // Camera position
    0.0f, 0.0f, 0.0f,  // Looking at
    0.0f, 1.0f, 0.0f  // Upward direction
  );

  // Draw a cube
  glBegin(GL_TRIANGLES);
  for (int face = 0; face < 6; face++) {
    // face color
    glColor3fv(colors[face]);

    for (int i = 0; i < 3; i++) {
      glVertex3fv(positions[faces[face * 2 + 0][i]]);
    }

    for (int i = 0; i < 3; i++) {
      glVertex3fv(positions[faces[face * 2 + 1][i]]);
    }
  }
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

