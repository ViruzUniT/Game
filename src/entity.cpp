#include "../include/entity.h"

#include <cstdio>

void Entity::AddTexture(GameTexture Texture) {
  // Textures[TextureName] = Texture;
  printf("%s\n", Texture.TextureName);
  Textures.insert(std::make_pair(Texture.TextureName, Texture));
  printf("%s\n", Textures.at(Texture.TextureName).TextureName);
}

bool Entity::SwitchCurrentTexture(const char* TextureName) {
  auto Texture = Textures.find(TextureName);
  if (Texture != Textures.end()) {
    std::cout << "Texture: " << TextureName << " was not found\n";
    return false;
  }
  CurrentTexture = Texture->second;
  // CurrentTexture = Textures[TextureName];
  return true;
}
