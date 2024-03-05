#pragma once

#include <cstring>

#include "SDL.h"
#include "eventhandler.h"
#include "game.h"
#include "math.h"

class Entity {
 public:
  Entity(Vector2 position, GameTexture texture, Vector4 currentFrame) : Position(position), Texture(texture) {
    CurrentFrame.x = currentFrame.x;
    CurrentFrame.y = currentFrame.y;
    CurrentFrame.w = currentFrame.w;
    CurrentFrame.h = currentFrame.h;
  }
  Entity(const Entity&) = delete;
  Entity(Entity&&) = delete;

  ~Entity() {
    if (Texture.texture != nullptr) {
      SDL_DestroyTexture(Texture.texture);
      Texture.texture = nullptr;
    }
  }

  inline Vector2 GetPosition() const { return Position; }
  inline void SetPosition(Vector2& NewPosition) { Position = NewPosition; }

  inline SDL_Texture* GetTexture() const { return Texture.texture; }
  inline const SDL_Rect* GetCurrentFrame() const { return &CurrentFrame; }

 protected:
  Vector2 Position;
  GameTexture Texture;
  SDL_Rect CurrentFrame;
};
