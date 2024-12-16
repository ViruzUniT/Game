#include "../include/object.h"

#include <cstring>
#include <iostream>

#include "../include/time.h"

#define FPS 10
#define NEWTEXTURE -1

extern Time Time;

void Object::AddTexture(GameTexture* Texture) {
  EntityTextures.push_back(Texture);
  std::cout << "Insert success\n";
}

bool Object::SwitchCurrentTexture(const char* TextureName) {
  // std::cout << "Switching Texture to: " << TextureName << std::endl;
  if (strcmp(TextureName, CurrentTexture.TextureName) == 0) {
    return true;
  }
  // Dont know why the fuck this doesnt work

  // if (Textures.find(TextureName) == Textures.end()) {
  //   std::cout << "Texture: " << TextureName << " was not found\n";
  //   return false;
  // }

  /*
   * DO NOT TOUCH IT WORKS SOMEHOW
   * i know it makes the use of a hashmap obsolete but Im not going to change it ... its
   * not a hashmap anymore
   */
  for (auto& kv : EntityTextures) {
    if (strcmp(kv->TextureName, TextureName) == 0) {
      CurrentTexture = *kv;
      ResetFrame();
      return true;
    }
  }

  std::cout << "Texture: " << TextureName << " was not found\n";
  return false;
}

void Object::SetFrameToStartPos(bool IsNewTexture) {
  Frame = 0;
  CurrentTexture.CurrentFrame.x = CurrentTexture.FirstCurrentFramePos;
  if (!IsNewTexture) {
    OnAnimationFinish.invoke(CurrentTexture);
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
    if (Frame < CurrentTexture.Frames)
      Frame += 1;

    CurrentTexture.CurrentFrame.x +=
        CurrentTexture.FrameOffset + CurrentTexture.CurrentFrame.w;

    if (Frame >= CurrentTexture.Frames)
      SetFrameToStartPos(false);
  }
}

void Object::ResetFrame() { Frame = NEWTEXTURE; }
