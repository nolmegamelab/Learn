#pragma once

#include <gfx/App.hpp>

namespace gfx {

class LearnSkeletalApp : public App
{
private: 

  Result OnInitialize() override;

  void OnDisplay() override;

  void OnFinish() override;

private: 
};

} // namespace gfx