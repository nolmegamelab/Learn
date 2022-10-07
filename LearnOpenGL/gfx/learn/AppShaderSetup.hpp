#pragma once

#include <gfx/App.hpp>

namespace gfx {

class AppShaderSetup : public App
{
private: 

  Result Initialize() override;

  void Update() override;

  void Finish() override;

private: 
  Result InitializeShaders();

  void InitializeVAOs();

private: 
  static constexpr int num_vao= 1;

  GLuint vao_[num_vao];
  GLuint shader_program_;
};

} // namespace gfx