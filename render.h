#pragma once
#include <memory>

namespace gllearn {
class ShaderProgram;
class Texture;

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

  std::shared_ptr<ShaderProgram> sp_;
  std::shared_ptr<Texture> tex_;
};
}  // namespace gllearn