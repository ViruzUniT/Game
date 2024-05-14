#pragma once

#include <vector>

#include "../include/SDL.h"
#include "entity.h"

extern std::vector<Entity*> EntityList;
class RenderWindow {
 public:
  RenderWindow(const char* WindowName, const int& WindowWidth, const int& WindowHeight);

  inline SDL_Window* GetWindow() { return window; };
  inline SDL_Renderer* GetRenderer() { return renderer; };

  int GetRefreshrate();
  double HiresTimeInSec();

  SDL_Texture* LoadTexture(const char* FilePath);

  void CleanUp();
  void Clear();
  void Render(const Entity& Entity);
  void Display();

  void DestroyWindowAndRenderer();

 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
