#include "shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "glad/glad.h"

using namespace gllearn;

bool Shader::Load(const std::string& file, int shader_type) {
  std::ifstream in;
  in.open(file, std::ifstream::in);
  if (in.fail()) return false;

  std::stringstream buffer;
  buffer << in.rdbuf();
  std::string code(buffer.str());

  shader_ = glCreateShader(shader_type);
  const char* cc = code.c_str();
  glShaderSource(shader_, 1, &cc, nullptr);
  glCompileShader(shader_);
  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(shader_, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader_, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    return false;
  }
  return true;
}

Shader::~Shader() { glDeleteShader(shader_); }

void Shader::AttachToProgram(const ShaderProgram& p) { p.AddShader(shader_); }

ShaderProgram::~ShaderProgram() { glDeleteProgram(shader_prog_); }
ShaderProgram::ShaderProgram() { shader_prog_ = glCreateProgram(); }

void ShaderProgram::Link() const { glLinkProgram(shader_prog_); }
void ShaderProgram::Use() const { glUseProgram(shader_prog_); }

void ShaderProgram::SetBool(const std::string& name, bool value) const {
  glUniform1i(glGetUniformLocation(shader_prog_, name.c_str()), (int)value);
}
void ShaderProgram::SetInt(const std::string& name, int value) const {
  glUniform1i(glGetUniformLocation(shader_prog_, name.c_str()), value);
}
void ShaderProgram::SetFloat(const std::string& name, float value) const {
  glUniform1f(glGetUniformLocation(shader_prog_, name.c_str()), value);
}

void ShaderProgram::AddShader(unsigned int id) const { glAttachShader(shader_prog_, id); }