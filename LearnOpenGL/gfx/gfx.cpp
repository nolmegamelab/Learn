#include <gfx/app.hpp>
#include <gfx/learn/LearnSkeletalApp.hpp>
#include <iostream>

namespace {

gfx::App* CreateApplication();

} // namespace

int main()
{
  auto app = CreateApplication();

  auto config = gfx::App::Config{ "First Example", 1280, 600 };

  app->Initialize(config); 
  app->Display();
  app->Finish();
}

namespace {

gfx::App* CreateApplication()
{
  return new gfx::LearnSkeletalApp();
}

} // namespace
