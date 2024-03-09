#include "../include/entity.h"

void Entity::AddTexture(GameTexture Texture) {
  // Textures[TextureName] = Texture;
  Textures.insert(std::make_pair(Texture.TextureName, Texture));
}

bool Entity::SwitchCurrentTexture(const char* TextureName) {
  auto Texture = Textures.find(TextureName);
  if (Texture == Textures.end()) {
    std::cout << "Texture: " << TextureName << "was not found\n";
    return false;
  }
  CurrentTexture = Texture->second;
  // CurrentTexture = Textures[TextureName];
  return true;
}
