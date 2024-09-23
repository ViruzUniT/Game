#include "../include/renderer.h"

#include <iostream>

#include "../include/entity.h"
#include "../include/game.h"

RenderWindow::RenderWindow(const char* WindowName, const int& WindowWidth, const int& WindowHeight) : window(nullptr), Renderer(nullptr) {
  window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cout << "Something went wrong: " << SDL_GetError() << std::endl;
    return;
  }

  Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (Renderer == nullptr) {
    std::cout << "Something went wrong: " << SDL_GetError() << std::endl;
  }
}

int RenderWindow::GetRefreshrate() {
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;
  SDL_GetDisplayMode(displayIndex, 0, &mode);
  return 60;
  // return mode.refresh_rate;
}

double RenderWindow::HiresTimeInSec() {
  double ticks = SDL_GetTicks();
  double time = ticks * 0.001f;
  return time;
}

SDL_Texture* RenderWindow::LoadTexture(const char* FilePath) {
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(Renderer, FilePath);

  if (texture == nullptr) {
    std::cout << "Texture load failed" << std::endl;
  }

  return texture;
}

void RenderWindow::CleanUp() { SDL_DestroyWindow(window); }

void RenderWindow::Clear() { SDL_RenderClear(Renderer); }

void RenderWindow::Render(Game* Game) {
  for (Entity* const entity : Game->GetEntityList()) {
    SDL_Rect dst;
    dst.x = entity->GetPosition().x;
    dst.y = entity->GetPosition().y;
    dst.w = 30;
    dst.h = 81;

    SDL_RenderCopy(Renderer, entity->GetTexture(), entity->GetCurrentFrame(), &dst);
  }
}

void RenderWindow::Display() { SDL_RenderPresent(Renderer); }

void RenderWindow::DestroyWindowAndRenderer() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(Renderer);
  window = nullptr;
  Renderer = nullptr;
}
