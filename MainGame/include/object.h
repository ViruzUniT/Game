#pragma once

#include <cstdint>
#include <cstring>

#include "SDL.h"
#include "eventhandler.h"
#include "game.h"
#include "math.h"
#include "texture.h"

class Object {
 public:
  Object(const char* EntityName, const Vector2& position, GameTexture* Texture,
      Game& Game)
      : Name(EntityName), Position(position), CurrentTexture(Texture) {
    AddTexture(Texture);
    std::cout << "Added Texture to list\n";
    ResetFrame();
    // SwitchCurrentTexture(Texture.TextureName);
  }
  Object(const Object&) = delete;
  Object(Object&&) = delete;

  ~Object() {
    for (const auto& texture : EntityTextures) {
      delete texture.second;
    }
  }

  inline Vector2 GetPosition() const { return Position; }
  inline void SetPosition(Vector2& NewPosition) { Position = NewPosition; }

  inline SDL_Texture* GetTexture() const { return CurrentTexture->Texture; }
  inline const SDL_Rect* GetCurrentFrame() const { return &CurrentTexture->CurrentFrame; }

  void AddTexture(GameTexture* Texture);
  bool SwitchCurrentTexture(std::string NewTextureName);
  inline std::string GetCurrentTextureName() const { return CurrentTexture->TextureName; }
  inline GameTexture* GetCurrentTexture() { return CurrentTexture; }

  void PlayAnimation();

  const char* Name;
  Event<GameTexture&> OnAnimationFinish;

 protected:
  void ResetFrame();
  void SetFrameToStartPos(bool IsNewTexture);

  int Frame;
  Event<GameTexture, GameTexture> OnTextureSwitch;
  Vector2 Position;
  GameTexture* CurrentTexture;
  std::unordered_map<std::string, GameTexture*> EntityTextures;
};
