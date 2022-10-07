#include <gfx/learn/AppShaderSetup.hpp>
#include <iostream>

namespace gfx {

App::Result AppShaderSetup::Initialize()
{
  auto config = gfx::App::Config{ "Shader Setup", 1280, 600 };

  InitializeConfig(config);
  auto rc = InitializeWindow();

  if (rc != Result::Success)
  {
    return rc;
  }

  rc = InitializeShaders();
  
  if (rc != Result::Success)
  {
    return rc;
  }

  InitializeVAOs();

  return Result::Success;
}

void AppShaderSetup::Update()
{
  while (!glfwWindowShouldClose(GetWindow()))
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(30);

    glBindVertexArray(vao_[0]);
    glUseProgram(shader_program_);
    glDrawArrays(GL_POINTS, 0, 1);

    glfwSwapBuffers(GetWindow());
    glfwPollEvents();
  }
}

void AppShaderSetup::Finish()
{
  glfwTerminate();
}

App::Result AppShaderSetup::InitializeShaders()
{
  const char* vshader_src = R"(
#version 430 
void main(void) 
{ 
  gl_Position = vec4(0.0, 0.0, 0.0, 1.0); 
}
)";

  const char* fshader_src = R"(
#version 430 
out vec4 color; 
void main(void) 
{ 
  if ( gl_FragCoord.x < 640 ) 
  {
    color = vec4(0.0, 0.0, 1.0, 1.0); 
  }
  else 
  {
    color = vec4(1.0, 0.0, 0.0, 1.0);
  }
}
)";

  auto vs = CreateVertexShader(vshader_src);
  auto fs = CreateFragmentShader(fshader_src);
  shader_program_ = CreateShaderProgram(vs, fs);

  // no longer required
  glDeleteShader(vs);
  glDeleteShader(fs);

  return Result::Success;
}

void AppShaderSetup::InitializeVAOs()
{
  glGenVertexArrays(num_vao, vao_);
}

} // namespace gfx

// ��ü ������ ���̴� ������ ����� ����: 
// - ���� ������ ����̽���  API�� �����ϱ� ���� ��� 
// - ���� üũ ���� ����� �������� �ʴ� ����̹����� ����. 
// - OpenGL�� ���� üũ�� �ſ� ���ϰ� ��� ������ ����� �� �˱� ��ƴ�. 
//  

