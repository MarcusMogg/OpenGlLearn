#pragma once

#include <string>

namespace gllearn {

class Shader {
 public:
  Shader() : shader_(0) {}
  ~Shader();

  bool Load(const std::string& file, int shader_type);

  void AttachToProgram(unsigned int shader_program);

 private:
  unsigned int shader_;
};

}  // namespace gllearn