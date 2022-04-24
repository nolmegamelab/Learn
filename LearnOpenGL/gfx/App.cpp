#include <gfx/app.hpp>
#include <iostream>

namespace gfx {

App::App()
{
}

App::~App()
{

}

void OnResize(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

App::Result App::Initialize(const Config& config)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(config.width, config.height, config.title.c_str(), NULL, NULL);
  if (window_ == nullptr)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return Result::Fail_GLFW_Initialize;
  }

  glfwMakeContextCurrent(window_);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return Result::Fail_Glad_Initialize;
  }

  glViewport(0, 0, config.width, config.height);

  glfwSetFramebufferSizeCallback(window_, OnResize);

  return OnInitialize();
}

void App::Display()
{
  while (!glfwWindowShouldClose(window_))
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    OnProcess();
    glfwSwapBuffers(window_);
    glfwPollEvents();
    OnDisplay();
  }
}

void App::Finish()
{
  OnFinish();
  glfwTerminate();
} 

App::Result App::OnInitialize()
{
  return Result::Success;
}

void App::OnProcess()
{
}

void App::OnDisplay()
{
}

void App::OnFinish()
{
}

} // namespace gfx


