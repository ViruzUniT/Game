#pragma once

#include <cstring>

#include "SDL.h"
#include "eventhandler.h"
#include "math.h"
#include "texture.h"

class Entity {
 public:
  Entity(Vector2 position, GameTexture texture) : Position(position), Texture(texture) {
    texture.CurrentFrame.x = Texture.CurrentFrame.x;
    texture.CurrentFrame.y = Texture.CurrentFrame.y;
    texture.CurrentFrame.w = Texture.CurrentFrame.w;
    texture.CurrentFrame.h = Texture.CurrentFrame.h;
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
  inline const SDL_Rect* GetCurrentFrame() const { return &Texture.CurrentFrame; }

 protected:
  Vector2 Position;
  GameTexture Texture;
};
