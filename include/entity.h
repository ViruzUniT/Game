#pragma once

#include "SDL.h"

struct Vector2 {
 public:
  Vector2() : x(0), y(0) {}
  Vector2(double x, double y) : x(x), y(y) {}

  Vector2(const Vector2& Original) {
    x = Original.x;
    y = Original.y;
  }

  Vector2(Vector2&& other) noexcept : x(other.x), y(other.y) {
    other.x = NULL;
    other.y = NULL;
  }

  double x, y;
};

class Entity {
 public:
  Entity(Vector2 position, SDL_Texture* texture) : Position(position), Texture(texture) {
    CurrentFrame.x = 100 - 54;
    CurrentFrame.y = 47;
    CurrentFrame.w = 30;
    CurrentFrame.h = 81;
  }

  inline Vector2 GetPosition() const { return Position; }

  inline SDL_Texture* GetTexture() const { return Texture; }
  inline SDL_Rect GetCurrentFrame() const { return CurrentFrame; }

 private:
  Vector2 Position;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
};
