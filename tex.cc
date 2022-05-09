#include "tex.h"

#include <iostream>

#include "glad/glad.h"
#include "stb_image.h"

using namespace gllearn;

Texture::Texture() {
  glGenTextures(1, &tex_);
  glBindTexture(GL_TEXTURE_2D, tex_);
  // 为当前绑定的纹理对象设置环绕、过滤方式
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

bool Texture::Load(const std::string& file) {
  int width, height, channels;
  unsigned char* data = stbi_load(file.c_str(), &width, &height, &channels, 0);
  if (data == nullptr) {
    std::cout << "Load" << file << " error\n";
    return false;
  }
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
  return true;
}

Texture::~Texture() {}

void Texture::Use() {
  glActiveTexture(GL_TEXTURE0);  // 在绑定纹理之前先激活纹理单元
  glBindTexture(GL_TEXTURE_2D, tex_);
}