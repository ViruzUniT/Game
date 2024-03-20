#include "../include/entity.h"

#include <cstdio>
#include <cstring>
#include <iostream>

#include "../include/time.h"

#define FPS 11.0f
#define NEWTEXTURE -1

extern Time Time;

void Entity::AddTexture(GameTexture Texture) {
  Textures.insert(std::make_pair(Texture.TextureName, Texture));
  printf("%s\n", Textures.at(Texture.TextureName).TextureName);
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
      CurrentTexture = kv.second;
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
  static float time = 0.0f;
  time += Time.deltaTime;
  float fps = 1 / time;
  if (fps <= FPS) {
    // shitty but it does its job
    if (strcmp(CurrentTexture.TextureName, "Walk") == 0) {
      printf("CurrentFrame: %d\n", CurrentTexture.CurrentFrame.x);
    } else {
      return;
    }
    if (Frame == NEWTEXTURE) {
      SetFrameToStartPos();
    }

    time = 0.0f;
    if (Frame <= CurrentTexture.Frames) {
      Frame += 1;
    }

    if (Frame == CurrentTexture.Frames) {
      SetFrameToStartPos();
      return;
    }

    CurrentTexture.CurrentFrame.x += CurrentTexture.FrameOffset + CurrentTexture.CurrentFrame.w;
  }
}

void Entity::ResetFrame() { Frame = -1; }
