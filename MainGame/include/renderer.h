#pragma once
#include <vector>

#include "SDL.h"

class Object;
class Game;

class RenderWindow {
 public:
  RenderWindow(const char* WindowName, const int& WindowWidth, const int& WindowHeight);
  RenderWindow() {}

  inline SDL_Window* GetWindow() const { return window; };
  inline SDL_Renderer* GetRenderer() const { return Renderer; };

  int GetRefreshrate() const;
  inline double HiresTimeInSec() const { return SDL_GetTicks() * 0.001f; }

  SDL_Texture* const LoadTexture(const char* FilePath) const;

  inline void CleanUp() const { SDL_DestroyWindow(window); }
  inline void Clear() const { SDL_RenderClear(Renderer); }
  void Render();
  void Display();

  void DestroyWindowAndRenderer();

 private:
  SDL_Window* window;
  SDL_Renderer* Renderer;
};
