#include "glfw.h"

#include <iostream>

#include "glad/glad.h"
// glad must bufore glfw
#include "GLFW/glfw3.h"

using namespace gllearn;
using namespace std;

Window::~Window() { glfwTerminate(); }

static void FramebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

int Window::Init() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window_ = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
  if (window_ == nullptr) {
    cout << "Failed to create GLFW window" << std::endl;
    return -1;
  }
  glfwSetFramebufferSizeCallback(window_, FramebufferSizeCallback);
  glfwMakeContextCurrent(window_);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  return 0;
}

void Window::Run() {
  while (!glfwWindowShouldClose(window_)) {
    ProcessInput();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window_);
  }
}

void Window::ProcessInput() const {
  for (const auto it : key_cb_) {
    if (glfwGetKey(window_, it.first) == GLFW_PRESS) {
      it.second(window_);
    }
  }
}