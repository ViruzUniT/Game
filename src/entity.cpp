#include "../include/entity.h"

void Entity::AddTexture(const char* TextureName, GameTexture Texture) { Textures[TextureName] = Texture; }

bool Entity::SwitchCurrentTexture(const char* TextureName) {
  auto it = Textures.find(TextureName);
  if (it == Textures.end()) {
    std::cout << "Texture: " << TextureName << "was not found\n";
    return false;
  }
  CurrentTexture = Textures[TextureName];
  return true;
}
