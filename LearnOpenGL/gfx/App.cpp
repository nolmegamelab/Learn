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

App::Result App::Initialize()
{
  return Result::Success;
}

void App::InitializeConfig(const Config& config)
{
  config_ = config;
}

App::Result App::InitializeWindow()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(config_.width, config_.height, config_.title.c_str(), NULL, NULL);
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

  glViewport(0, 0, config_.width, config_.height);

  glfwSetFramebufferSizeCallback(window_, OnResize);

  return Result::Success;
}

void App::Update()
{
}

void App::Finish()
{
  glfwTerminate();
} 

GLuint App::CreateVertexShader(const char* src)
{
  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &src, NULL);
  glCompileShader(vertex_shader);
  CheckErrorInOpenGL();

  GLint vert_compiled = 0;
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vert_compiled);
  if (!vert_compiled)
  {
    PrintShaderLog(vertex_shader);
  }

  return vertex_shader;
}

GLuint App::CreateFragmentShader(const char* src)
{
  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &src, NULL);
  glCompileShader(fragment_shader);
  CheckErrorInOpenGL();

  GLint fs_compiled = 0;
  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &fs_compiled);
  if (!fs_compiled)
  {
    PrintShaderLog(fragment_shader);
  }

  return fragment_shader;
}

GLuint App::CreateShaderProgram(GLuint vertex_shader, GLuint fragment_shader)
{
  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);
  glLinkProgram(shader_program);
  CheckErrorInOpenGL();

  GLint linked = 0;

  glGetProgramiv(shader_program, GL_LINK_STATUS, &linked);
  if (linked != 1)
  {
    PrintProgramLog(shader_program);
  }

  return shader_program;
}

void App::PrintShaderLog(GLuint shader) 
{
  int len = 0;
  int chWrittn = 0;
  char* log;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
  if (len > 0) 
  {
    log = (char*)::alloca(len);
    glGetShaderInfoLog(shader, len, &chWrittn, log);
    std::cout << "Shader Info Log: " << log << std::endl;
  }
}
void App::PrintProgramLog(GLuint prog) 
{
  int len = 0;
  int chWrittn = 0;
  char* log;
  glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
  if (len > 0) 
  {
    log = (char*)::alloca(len);
    glGetProgramInfoLog(prog, len, &chWrittn, log);
    std::cout << "Program Info Log: " << log << std::endl;
  }
}

bool App::CheckErrorInOpenGL() 
{
  bool foundError = false;
  int glErr = glGetError();
  while (glErr != GL_NO_ERROR) 
  {
    std::cout << "glError: " << glErr << std::endl;
    foundError = true;
    glErr = glGetError();
  }
  return foundError;
}

} // namespace gfx


