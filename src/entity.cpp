#include "../include/entity.h"

#include <cstdio>
#include <cstring>
#include <iostream>

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
