#pragma once

#include <vector>

#include "SDL.h"

class Entity;
class Game;

class RenderWindow {
 public:
  RenderWindow(const char* WindowName, const int& WindowWidth, const int& WindowHeight);
  RenderWindow() {}

  inline SDL_Window* GetWindow() { return window; };
  inline SDL_Renderer* GetRenderer() { return Renderer; };

  int GetRefreshrate();
  double HiresTimeInSec();

  SDL_Texture* const LoadTexture(const char* FilePath);

  void CleanUp();
  void Clear();
  void Render(Game* Game);
  void Display();

  void DestroyWindowAndRenderer();

 private:
  SDL_Window* window;
  SDL_Renderer* Renderer;
};
