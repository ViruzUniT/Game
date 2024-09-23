#include "../include/entity.h"

#include <cstring>
#include <iostream>

#include "../include/time.h"

#define FPS 10
#define NEWTEXTURE -1

extern Time Time;

void Entity::AddTexture(GameTexture* Texture) {
  Textures.push_back(Texture);
  std::cout << "Insert success\n";
}

bool Entity::SwitchCurrentTexture(const char* TextureName) {
  std::cout << "Switching Texture to: " << TextureName << std::endl;
  if (strcmp(TextureName, CurrentTexture.TextureName) == 0) {
    return true;
  }

  // Dont know why the fuck this doesnt work

  // if (Textures.find(TextureName) == Textures.end()) {
  //   std::cout << "Texture: " << TextureName << " was not found\n";
  //   return false;
  // }

  // DO NOT TOUCH IT WORKS SOMEHOW
  // i know it makes the use of a hashmap obsolete but Im not going to change it
  const auto& textures = Textures;
  for (auto& kv : textures) {
    if (strcmp(kv->TextureName, TextureName) == 0) {
      CurrentTexture = *kv;
      ResetFrame();
      return true;
    }
  }

  std::cout << "Texture: " << TextureName << " was not found\n";
  return false;
}

void Entity::SetFrameToStartPos() {
  Frame = 0;
  CurrentTexture.CurrentFrame.x = CurrentTexture.FirstCurrentFramePos;
  CurrentTexture.OnAnimationFinish.invoke();
}

void Entity::PlayAnimation() {
  // shitty but it does its job
  // static double time;
  // time += Time.deltaTime;
  // double fps = 1 / time;
  static int fps;
  fps += 1;
  if (fps == FPS) {
    fps = 0;
    if (Frame == NEWTEXTURE)
      SetFrameToStartPos();
    if (Frame < CurrentTexture.Frames)
      Frame += 1;

    CurrentTexture.CurrentFrame.x += CurrentTexture.FrameOffset + CurrentTexture.CurrentFrame.w;

    if (Frame == CurrentTexture.Frames)
      SetFrameToStartPos();
  }
}

void Entity::ResetFrame() { Frame = NEWTEXTURE; }
