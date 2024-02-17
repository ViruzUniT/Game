#pragma once

#include "SDL.h"

struct Vector2 {
 public:
  Vector2() : x(0), y(0) {}
  Vector2(double x, double y) : x(x), y(y) {}

 private:
  double x, y;
};

class Entity {
 public:
  // Entity();
  Entity(double x, double y, SDL_Texture* texture) : x(x), y(y), Texture(texture) {
    CurrentFrame.x = 100 - 54;
    CurrentFrame.y = 47;
    CurrentFrame.w = 30;
    CurrentFrame.h = 81;
  }

  inline float GetX() const { return x; }
  inline float GetY() const { return y; }

  inline SDL_Texture* GetTexture() const { return Texture; }
  inline SDL_Rect GetCurrentFrame() const { return CurrentFrame; }

 private:
  double x, y;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
};
