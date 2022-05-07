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

void Shader::AttachToProgram(unsigned int shader_program) { glAttachShader(shader_program, shader_); }