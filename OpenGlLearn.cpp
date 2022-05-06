// OpenGlLearn.cpp: 定义应用程序的入口点。
//

#include "OpenGlLearn.h"

#include "glad/glad.h"
// glad must bufore glfw
#include "GLFW/glfw3.h"

using namespace std;
using namespace gllearn;

int main() {
  Window window;
  window.Init();
  window.RegisterKey(GLFW_KEY_ESCAPE, [](GLFWwindow* window) { glfwSetWindowShouldClose(window, true); });
  window.Run();
  return 0;
}
