#pragma once

#include <cstdint>
#include <cstring>
#include <unordered_map>

#include "SDL.h"
#include "eventhandler.h"
#include "math.h"
#include "texture.h"

class Entity {
 public:
  Entity(Vector2 position, GameTexture texture) : Position(position), CurrentTexture(texture) { AddTexture(texture); }
  Entity(const Entity&) = delete;
  Entity(Entity&&) = delete;

  ~Entity() {
    if (CurrentTexture.Texture != nullptr) {
      SDL_DestroyTexture(CurrentTexture.Texture);
      CurrentTexture.Texture = nullptr;
    }
  }

  inline Vector2 GetPosition() const { return Position; }
  inline void SetPosition(Vector2& NewPosition) { Position = NewPosition; }

  inline SDL_Texture* GetTexture() const { return CurrentTexture.Texture; }
  inline const SDL_Rect* GetCurrentFrame() const { return &CurrentTexture.CurrentFrame; }

  void AddTexture(GameTexture Texture);
  bool SwitchCurrentTexture(const char* NewTextureName);
  char* GetCurrentTextureName();
  GameTexture GetCurrentTexture();

  void PlayAnimation();

 protected:
  void ResetFrame();
  void SetFrameToStartPos();

  int Frame;
  Event<> OnTextureSwitch;
  Vector2 Position;
  GameTexture CurrentTexture;
  std::unordered_map<const char*, GameTexture> Textures;
};
