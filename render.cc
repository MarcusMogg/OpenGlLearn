#include "render.h"

#include "glad/glad.h"
#include "shader.h"
using namespace gllearn;

static const float vertices[] = {
    0.5f,
    -0.5f,
    0.0f,
    1.0f,
    0.0f,
    0.0f,  // 右下
    -0.5f,
    -0.5f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,  // 左下
    0.0f,
    0.5f,
    0.0f,
    0.0f,
    0.0f,
    1.0f  // 顶部
};
static const unsigned int indices[] = {
    // note that we start from 0!
    0,
    1,
    2,  // first Triangle
        // 1,
        // 2,
        // 3  // second Triangle
};

void Renderer::Init() {
  // load shader
  sp_ = std::make_shared<ShaderProgram>();
  Shader vertex, frag;
  vertex.Load("./shaders/002/vertex.glsl", GL_VERTEX_SHADER);
  frag.Load("./shaders/002/fragment.glsl", GL_FRAGMENT_SHADER);
  vertex.AttachToProgram(*sp_);
  frag.AttachToProgram(*sp_);
  sp_->Link();

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // 位置属性
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // 颜色属性
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex
  // buffer object so afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);
}

void Renderer::Render() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  sp_->Use();
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Renderer::~Renderer() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}