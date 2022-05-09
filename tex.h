#pragma once

#include <string>

namespace gllearn {

class Texture {
 public:
  Texture();
  ~Texture();

  bool Load(const std::string& file);

  void Use();

 private:
  unsigned int tex_;
};

}  // namespace gllearn