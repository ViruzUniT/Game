#include "../include/renderer.h"

#include <iostream>

#include "../include/entity.h"
#include "../include/game.h"
#include "../include/world.h"

RenderWindow::RenderWindow(const char* WindowName, const int& WindowWidth,
    const int& WindowHeight)
    : window(nullptr), Renderer(nullptr) {
  window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cout << "Something went wrong: " << SDL_GetError() << std::endl;
    return;
  }

  Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (Renderer == nullptr) {
    std::cout << "Something went wrong: " << SDL_GetError() << std::endl;
  }
}

int RenderWindow::GetRefreshrate() const {
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;
  SDL_GetDisplayMode(displayIndex, 0, &mode);
  return 60;
  // return mode.refresh_rate;
}

SDL_Texture* const RenderWindow::LoadTexture(const char* FilePath) const {
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(Renderer, FilePath);

  if (texture == nullptr) {
    std::cout << "Texture load failed" << std::endl;
  }

  return texture;
}

void RenderWindow::Render(const Game* const Game) {
  for (auto& entity : World::GetEntities()) {
    // std::cout << "Current EntityTexture: " << entity->GetTexture() << std::endl;

    SDL_Rect dst;
    dst.x = entity->GetPosition().x;
    dst.y = entity->GetPosition().y;
    dst.w = entity->GetCurrentTexture()->CurrentFrame.w;
    dst.h = entity->GetCurrentTexture()->CurrentFrame.h;

    int Error = SDL_RenderCopy(Renderer, entity->GetCurrentTexture()->Texture,
        entity->GetCurrentFrame(), &dst);
    if (Error != 0) {
      std::cout << "Render Error: " << SDL_GetError() << std::endl;
    }
  }
}

void RenderWindow::Display() { SDL_RenderPresent(Renderer); }

void RenderWindow::DestroyWindowAndRenderer() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(Renderer);
  window = nullptr;
  Renderer = nullptr;
}
