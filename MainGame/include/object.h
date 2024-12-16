#pragma once
#include <cstdint>
#include <cstring>

#include "SDL.h"
#include "eventhandler.h"
#include "math.h"
#include "texture.h"

class Object {
 public:
  Object(const char* EntityName, const Vector2& position) : Name(EntityName), Position(position) {
    std::cout << "Added Texture to list\n";
    ResetFrame();

    RunTick = false;
  }
  Object(const char* EntityName, const Vector2& position, GameTexture* Texture)
      : Name(EntityName), Position(position), CurrentTexture(Texture) {
    AddTexture(Texture);
    std::cout << "Added Texture to list\n";
    ResetFrame();

    RunTick = false;
  }
  Object(const Object&) = delete;
  Object(Object&&) = delete;

  ~Object() {
    for (const auto& texture : EntityTextures) {
      delete texture.second;
    }
  }

  virtual void Start() {}
  virtual void Tick() {}

  inline bool GetRunTick() { return RunTick; }

  inline Vector2 GetPosition() const { return Position; }
  inline void SetPosition(Vector2& NewPosition) { Position = NewPosition; }

  inline SDL_Texture* GetTexture() const { return CurrentTexture->Texture; }
  inline const SDL_Rect* GetCurrentFrame() const { return &CurrentTexture->CurrentFrame; }

  GameTexture* LoadTexture(const char* TextureName, const char* SpriteLocation,
      const Vector4& CurrentFrame, const int& FrameOffset, const int& Frames);
  void AddTexture(GameTexture* Texture);
  bool SwitchCurrentTexture(std::string NewTextureName);
  inline std::string GetCurrentTextureName() const { return CurrentTexture->TextureName; }
  inline GameTexture* GetCurrentTexture() { return CurrentTexture; }

  void PlayAnimation();

  const char* Name;
  Event<GameTexture&> OnAnimationFinish;

 protected:
  bool RunTick;

  void ResetFrame();
  void SetFrameToStartPos(bool IsNewTexture);

  int Frame;
  Event<GameTexture, GameTexture> OnTextureSwitch;
  Vector2 Position;
  GameTexture* CurrentTexture;
  std::unordered_map<std::string, GameTexture*> EntityTextures;
};
