#include <iostream>
#include <string>
#include <format>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

static int WIN_WIDTH = 640;
static int WIN_HEIGHT = 480;
static const char *WIN_TITLE = "OpenGL sandbox";

static const double FPS = 30.0;
static float ROT_ANGLE = 0.0f;

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

void drawCube() {
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

void paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Coordinate transformation
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT, 1.0f, 10.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(
    3.0f, 4.0f, 5.0f,  // Camera position
    0.0f, 0.0f, 0.0f,  // Looking at
    0.0f, 1.0f, 0.0f  // Upward direction
  );

  // First cube
  glPushMatrix();
  glTranslatef(-1.0f, 0.0f, 0.0f);
  glRotatef(ROT_ANGLE, 0.0f, 1.0f, 0.0f);
  glRotatef(ROT_ANGLE * 0.5f, 1.0f, 0.0f, 0.0f);
  glScalef(0.5f, 0.5f, 0.5f);

  drawCube();
  glPopMatrix();

  // Second cube
  glPushMatrix();
  glTranslatef(1.0f, 0.0f, 0.0f);
  glRotatef(2.0f * ROT_ANGLE, 0.0f, 1.0f, 0.0f);
  glRotatef(ROT_ANGLE, 1.0f, 0.0f, 0.0f);
  glScalef(0.5f, 0.5f, 0.5f);

  drawCube();
  glPopMatrix();
}

void resizeGL(GLFWwindow *window, int width, int height) {
  // Update user-managed window size
  WIN_WIDTH = width;
  WIN_HEIGHT = height;

  // Update GLFW-managed window size
  glfwSetWindowSize(window, WIN_WIDTH, WIN_HEIGHT);

  // Get actual window size by pixels
  int renderBufferWidth, renderBufferHeight;
  glfwGetFramebufferSize(window, &renderBufferWidth, &renderBufferHeight);

  // Update viewport transform
  glViewport(0, 0, renderBufferWidth, renderBufferHeight);
}

void animate() {
  ROT_ANGLE += 1.0f;
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

  // Specify window as an OpenGL context
  glfwMakeContextCurrent(window);

  // Register a callback function for window resizeing
  glfwSetWindowSizeCallback(window, resizeGL);

  initializeGL();

  double prevTime = glfwGetTime();
  while (glfwWindowShouldClose(window) == GLFW_FALSE) {
    double currentTime = glfwGetTime();

    if (currentTime - prevTime >= 1.0 / FPS) {
      double realFps = 1.0 / (currentTime - prevTime);
      const std::string winTitle = std::format("{} (FPS: {:.3f})", WIN_TITLE, realFps);
      glfwSetWindowTitle(window, winTitle.c_str());

      paintGL();

      animate();

      glfwSwapBuffers(window);
      glfwPollEvents();

      prevTime = currentTime;
    }
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

