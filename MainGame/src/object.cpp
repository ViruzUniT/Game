#include "../include/object.h"

#include <iostream>

#include "../include/time.h"

#define FPS 10
#define NEWTEXTURE -1

extern Time Time;

void Object::AddTexture(GameTexture* Texture) {
  EntityTextures[Texture->TextureName] = Texture;
  std::cout << "Insert success\n";
}

bool Object::SwitchCurrentTexture(std::string TextureName) {
  if (CurrentTexture->TextureName == TextureName) {
    return true;
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

    CurrentTexture->CurrentFrame.x +=
        CurrentTexture->FrameOffset + CurrentTexture->CurrentFrame.w;

    if (Frame >= CurrentTexture->Frames)
      SetFrameToStartPos(false);
  }
}

void Object::ResetFrame() { Frame = NEWTEXTURE; }
