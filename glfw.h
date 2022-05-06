#pragma once
#include <functional>
#include <map>

#include "glad/glad.h"
// glad must bufore glfw
#include "GLFW/glfw3.h"

namespace gllearn {
class Window {
 public:
  using KeyCallBack = std::function<void(GLFWwindow*)>;

  Window() : window_(nullptr) {}
  ~Window();

  int Init();
  void Run();

  void RegisterKey(int key, KeyCallBack cb) { key_cb_[key] = cb; }

 private:
  GLFWwindow* window_;

  std::map<int, KeyCallBack> key_cb_;

  void ProcessInput() const;
};

}  // namespace gllearn