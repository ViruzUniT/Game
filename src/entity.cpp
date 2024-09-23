#include "../include/entity.h"

#include <cstdio>
#include <cstring>
#include <iostream>

#include "../include/time.h"

#define FPS 10
#define NEWTEXTURE -1

extern Time Time;

void Entity::AddTexture(GameTexture Texture) {
  std::cout << "Inserting texture: " << Texture.TextureName << std::endl;
  Textures.insert(std::make_pair(Texture.TextureName, &Texture));
  std::cout << "Insert success\n";
  printf("%s\n", Textures.at(Texture.TextureName)->TextureName);
}

bool Entity::SwitchCurrentTexture(const char* TextureName) {
  if (strcmp(TextureName, CurrentTexture.TextureName) == 0) {
    return true;
  }

  // Dont know why the fuck this doesnt work

  // if (textures.find(TextureName) == textures.end()) {
  //   std::cout << "Texture: " << TextureName << " was not found\n";
  //   return false;
  // }

  // DO NOT TOUCH IT WORKS SOMEHOW
  // i know it makes the use of a hashmap obsolete but Im not going to change it
  const auto& textures = Textures;
  for (auto& kv : textures) {
    if (strcmp(kv.first, TextureName) == 0) {
      CurrentTexture = *kv.second;
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

void Entity::ResetFrame() { Frame = -1; }
