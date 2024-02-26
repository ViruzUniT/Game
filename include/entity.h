#pragma once

#include <cstring>

#include "SDL.h"
#include "eventhandler.h"
#include "math.h"

class Entity {
 public:
  Entity(Vector2 position, SDL_Texture* texture, Vector4 currentFrame) : Position(position), Texture(texture) {
    CurrentFrame.x = currentFrame.x;
    CurrentFrame.y = currentFrame.y;
    CurrentFrame.w = currentFrame.w;
    CurrentFrame.h = currentFrame.h;
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

 protected:
  Vector2 Position;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
};
