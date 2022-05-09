
# CMakeList.txt: OpenGlLearn 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("OpenGlLearn")

include(FetchContent)
FetchContent_Declare(
  glfw
  URL https://github.com/glfw/glfw/releases/download/3.3.7/glfw-3.3.7.zip
)

FetchContent_MakeAvailable(glfw)

find_package(opengl REQUIRED)

# 将源代码添加到此项目的可执行文件。
add_executable (OpenGlLearn 
	"OpenGlLearn.cpp" 
	"OpenGlLearn.h"
	"glad/glad.c"
	"glad/glad.h"
	"glad/khrplatform.h"
	"glfw.h"
	"glfw.cc"
	"shader.h"
	"shader.cc"
	"render.h"
	"render.cc"
	"stb_image.h"
	"stb_image.cc"
)

target_link_libraries(OpenGlLearn
	PRIVATE
		glfw
		opengl32
)

# 资源文件
FILE(GLOB SHADER "shaders/*")
FILE(COPY ${SHADER} DESTINATION "${PROJECT_BINARY_DIR}/shaders")

# TODO: 如有需要，请添加测试并安装目标。
