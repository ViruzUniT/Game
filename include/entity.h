#pragma once

#include <cstring>

#include "SDL.h"
#include "eventhandler.h"

struct Vector2 {
 public:
  Vector2() : x(0), y(0) {}
  Vector2(double x, double y) : x(x), y(y) {}

  double x, y;
};

class Entity {
 public:
  Entity(Vector2 position, SDL_Texture* texture) : Position(position), Texture(texture) {
    CurrentFrame.x = 46;
    CurrentFrame.y = 47;
    CurrentFrame.w = 30;
    CurrentFrame.h = 81;
  }
  Entity(const Entity&) = delete;
  Entity(Entity&&) = delete;

  ~Entity() {
    if (Texture != nullptr) {
      SDL_DestroyTexture(Texture);
      Texture = nullptr;
    }
  }
  inline Vector2 GetPosition() const { return Position; }
  inline void SetPosition(Vector2& NewPosition) { Position = NewPosition; }

  inline SDL_Texture* GetTexture() const { return Texture; }
  inline const SDL_Rect* GetCurrentFrame() const { return &CurrentFrame; }

 private:
  Vector2 Position;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
};
