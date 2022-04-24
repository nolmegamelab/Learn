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

  Result Initialize(const Config& config);

  void Display();

  void Finish();

  GLFWwindow* GetWindow() const
  {
    return window_;
  }

protected: 
  virtual Result OnInitialize(); 

  virtual void OnProcess();

  virtual void OnDisplay();

  virtual void OnFinish();

private:
  GLFWwindow* window_;
};

} // namespace gfx