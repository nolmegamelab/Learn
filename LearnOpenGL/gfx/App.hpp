#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace gfx {

class App
{
public:
  enum class Result {
    Success,
    Fail_GLFW_Initialize,
    Fail_Glad_Initialize
  };

  struct Config
  {
    std::string title;
    uint32_t width; 
    uint32_t height;
  };

public:
  App();

  virtual ~App();

  virtual Result Initialize();

  virtual void Update();

  virtual void Finish();

  GLFWwindow* GetWindow() const
  {
    return window_;
  }

protected: 
  void InitializeConfig(const Config& config);

  Result InitializeWindow();

  GLuint CreateVertexShader(const char* src);

  GLuint CreateFragmentShader(const char* src);

  GLuint CreateShaderProgram(GLuint vertex_shader, GLuint fragment_shader);

  void PrintShaderLog(GLuint shader);

  void PrintProgramLog(GLuint prog);

  bool CheckErrorInOpenGL();

private:
  GLFWwindow* window_;
  Config config_;
};

} // namespace gfx