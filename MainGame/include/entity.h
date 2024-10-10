#pragma once

#include <cstdint>
#include <cstring>

#include "SDL.h"
#include "eventhandler.h"
#include "game.h"
#include "math.h"
#include "texture.h"

class Entity {
 public:
  Entity(const char* EntityName, const Vector2& position, GameTexture* Texture, Game& Game)
      : Name(EntityName), Position(position), CurrentTexture(*Texture) {
    AddTexture(Texture);
    std::cout << "Added Texture to list\n";
    ResetFrame();
    // SwitchCurrentTexture(Texture.TextureName);
  }
  Entity(const Entity&) = delete;
  Entity(Entity&&) = delete;

  ~Entity() {
    for (GameTexture* texture : EntityTextures) {
      delete texture;
    }
  }

  inline Vector2 GetPosition() const { return Position; }
  inline void SetPosition(Vector2& NewPosition) { Position = NewPosition; }

  inline SDL_Texture* GetTexture() const { return CurrentTexture.Texture; }
  inline const SDL_Rect* GetCurrentFrame() const { return &CurrentTexture.CurrentFrame; }

  void AddTexture(GameTexture* Texture);
  bool SwitchCurrentTexture(const char* NewTextureName);
  inline const char* GetCurrentTextureName() const { return CurrentTexture.TextureName; }
  inline GameTexture* GetCurrentTexture() { return &CurrentTexture; }

  void PlayAnimation();

  const char* Name;
  Event<GameTexture&> OnAnimationFinish;

 protected:
  void ResetFrame();
  void SetFrameToStartPos(bool IsNewTexture);

  int Frame;
  Event<GameTexture, GameTexture> OnTextureSwitch;
  Vector2 Position;
  GameTexture CurrentTexture;
  std::vector<GameTexture*> EntityTextures;
};
