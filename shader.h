#pragma once

#include <string>

namespace gllearn {
class ShaderProgram;

class Shader {
 public:
  Shader() : shader_(0) {}
  ~Shader();

  bool Load(const std::string& file, int shader_type);

  void AttachToProgram(const ShaderProgram& p);

 private:
  unsigned int shader_;
};

class ShaderProgram {
 public:
  ShaderProgram();
  ~ShaderProgram();

  // 使用/激活程序
  void Link() const;
  void Use() const;
  // uniform工具函数
  void SetBool(const std::string& name, bool value) const;
  void SetInt(const std::string& name, int value) const;
  void SetFloat(const std::string& name, float value) const;

  void AddShader(unsigned int id) const;

 private:
  unsigned int shader_prog_;
};

}  // namespace gllearn