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

// 자체 포맷의 쉐이더 문법을 만드는 이유: 
// - 여러 렌더링 디바이스나  API에 적용하기 위한 방법 
// - 에러 체크 등이 제대로 지원되지 않는 드라이버들이 많음. 
// - OpenGL의 에러 체크도 매우 약하고 어디서 문제가 생겼는 지 알기 어렵다. 
//  

