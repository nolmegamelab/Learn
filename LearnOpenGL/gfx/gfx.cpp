#include <gfx/app.hpp>
#include <gfx/learn/AppShaderSetup.hpp>
#include <iostream>

namespace {

gfx::App* CreateApplication();

} // namespace

int main()
{
  auto app = CreateApplication();

  app->Initialize(); 
  app->Update();
  app->Finish();
}

namespace {

gfx::App* CreateApplication()
{
  return new gfx::AppShaderSetup();
}

} // namespace
