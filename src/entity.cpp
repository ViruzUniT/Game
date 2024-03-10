#include "../include/entity.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#include "../include/time.h"

#define FPS 11.0f

extern Time Time;

void Entity::AddTexture(GameTexture Texture) {
  Textures.insert(std::make_pair(Texture.TextureName, Texture));
  printf("%s\n", Textures.at(Texture.TextureName).TextureName);
}

bool Entity::SwitchCurrentTexture(const char* TextureName) {
  const auto& textures = Textures;

  // Dont know why the fuck this doesnt work

  // if (textures.find(TextureName) == textures.end()) {
  //   std::cout << "Texture: " << TextureName << " was not found\n";
  //   return false;
  // }

  // DO NOT TOUCH IT WORKS SOMEHOW
  // i know it makes the use of a hashmap obsolete but Im not going to change it
  for (auto& kv : textures) {
    if (strcmp(kv.first, TextureName) == 0) {
      CurrentTexture = kv.second;
      return true;
    }
  }

  std::cout << "Texture: " << TextureName << " was not found\n";
  return false;
}

void Entity::PlayAnimation() {
  static uint16_t Frame = 0;

  static float time = 0.0f;
  time += Time.deltaTime;
  float fps = 1 / time;
  if (fps <= FPS) {
    // shitty but it does its job
    static std::string currentAnimName = "";
    std::cout << currentAnimName << "\n";
    if (strcmp(CurrentTexture.TextureName, currentAnimName.c_str()) != 0) {
      Frame = 0;
    }
    currentAnimName = CurrentTexture.TextureName;
    time = 0.0f;
    if (Frame < CurrentTexture.Frames) {
      Frame += 1;
    }

    if (Frame == CurrentTexture.Frames) {
      Frame = 0;
      CurrentTexture.CurrentFrame.x = CurrentTexture.FirstCurrentFramePos;
      CurrentTexture.OnAnimationFinish.invoke();
      return;
    }

    CurrentTexture.CurrentFrame.x += CurrentTexture.FrameOffset + CurrentTexture.CurrentFrame.w;
  }
}
