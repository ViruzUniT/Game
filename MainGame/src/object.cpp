#include "../include/object.h"

#include <iostream>

#include "../include/game.h"
#include "../include/time.h"
#include "../include/world.h"

#define FPS 10
#define NEWTEXTURE -1

extern Time Time;

GameTexture* Object::LoadTexture(const char* TextureName, const char* SpriteLocation,
    const Vector4& CurrentFrame, const int& FrameOffset, const int& Frames) {
  SDL_Texture* texture = World::GetCurrentGame()->GetWindow()->LoadTexture(SpriteLocation);
  if (texture == nullptr) {
    std::cout << "Texture Creation failed\n";
    return nullptr;
  }

  SDL_Rect currentFrame;
  currentFrame.x = CurrentFrame.x;
  currentFrame.y = CurrentFrame.y;
  currentFrame.h = CurrentFrame.h;
  currentFrame.w = CurrentFrame.w;
  return new GameTexture(TextureName, texture, currentFrame, FrameOffset, Frames);
}

void Object::AddTexture(GameTexture* Texture) {
  if (Texture == nullptr) {
    return;
  }
  EntityTextures[Texture->TextureName] = Texture;
  std::cout << "Insert success\n";
}

bool Object::SwitchCurrentTexture(std::string TextureName) {
  if (CurrentTexture != nullptr) {
    if (CurrentTexture->TextureName == TextureName) {
      return true;
    }
  }
  if (EntityTextures.find(TextureName) == EntityTextures.end()) {
    std::cout << "Texture: " << TextureName << " was not found 0x1\n";
    return false;
  }
  CurrentTexture = EntityTextures.find(TextureName)->second;
  ResetFrame();
  return true;
}

void Object::SetFrameToStartPos(bool IsNewTexture) {
  Frame = 0;
  CurrentTexture->CurrentFrame.x = CurrentTexture->FirstCurrentFramePos;
  if (!IsNewTexture) {
    OnAnimationFinish.invoke(*CurrentTexture);
  }
}

void Object::PlayAnimation() {
  // shitty but it does its job
  // static double time;
  // time += Time.deltaTime;
  // double fps = 1 / time;
  static int fps;
  fps += 1;
  if (fps == FPS) {
    fps = 0;
    if (Frame == NEWTEXTURE)
      SetFrameToStartPos(true);
    if (Frame < CurrentTexture->Frames)
      Frame += 1;

    CurrentTexture->CurrentFrame.x += CurrentTexture->FrameOffset + CurrentTexture->CurrentFrame.w;

    if (Frame >= CurrentTexture->Frames)
      SetFrameToStartPos(false);
  }
}

void Object::ResetFrame() { Frame = NEWTEXTURE; }
