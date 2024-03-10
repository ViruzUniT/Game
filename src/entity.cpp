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
  // if (textures.find(TextureName) == textures.end()) {
  //   std::cout << "Texture: " << TextureName << " was not found\n";
  //   return false;
  // }
  for (auto& kv : textures) {
    std::cout << kv.second.TextureName << ", " << TextureName << ", " << (kv.second.TextureName == TextureName) << ", "
              << strcmp(kv.second.TextureName, TextureName) << "\n";
    if (strcmp(kv.first, TextureName) == 0) {
      CurrentTexture = kv.second;
      return true;
    }
  }

  std::cout << "Texture: " << TextureName << " was not found\n";
  return false;
}
