#pragma once

namespace gllearn {
class Renderer {
 public:
  Renderer() : VAO(0), VBO(0), EBO(0), shader(0) {}
  ~Renderer();

  void Init();
  void Render();

 private:
  unsigned int VAO;  // vertex array object
  unsigned int VBO;  // vertex data buff
  unsigned int EBO;  // index buff
  unsigned int shader;
};
}  // namespace gllearn