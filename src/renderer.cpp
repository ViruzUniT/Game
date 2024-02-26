#include "../include/renderer.h"

#include <iostream>

RenderWindow::RenderWindow(const char* WindowName, const int& WindowWidth, const int& WindowHeight) : window(nullptr), renderer(nullptr) {
  window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cout << "Something went wrong: " << SDL_GetError() << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::cout << "Something went wrong: " << SDL_GetError() << std::endl;
  }
}

int RenderWindow::GetRefreshrate() {
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;
  SDL_GetDisplayMode(displayIndex, 0, &mode);
  return mode.refresh_rate;
}

float RenderWindow::HiresTimeInSec() {
  float ticks = SDL_GetTicks();
  float time = ticks * 0.001f;
  return time;
}

SDL_Texture* RenderWindow::LoadTexture(const char* FilePath) {
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(renderer, FilePath);

  if (texture == nullptr) {
    std::cout << "Texture load failed" << std::endl;
  }

  return texture;
}

void RenderWindow::CleanUp() { SDL_DestroyWindow(window); }

void RenderWindow::Clear() { SDL_RenderClear(renderer); }

void RenderWindow::Render(const Entity& Entity) {
  SDL_Rect dst;
  dst.x = Entity.GetPosition().x;
  dst.y = Entity.GetPosition().y;
  dst.w = 30;
  dst.h = 81;

  SDL_RenderCopy(renderer, Entity.GetTexture(), Entity.GetCurrentFrame(), &dst);
}

void RenderWindow::Display() { SDL_RenderPresent(renderer); }

void RenderWindow::DestroyWindowAndRenderer() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  window = nullptr;
  renderer = nullptr;
}
