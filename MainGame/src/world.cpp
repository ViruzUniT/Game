#include "../include/world.h"

namespace World {
std::vector<Entity*> EntityList;
std::vector<Entity*> GetEntities() { return EntityList; }

/**
 * Returns first Entity with the given Name
 *
 * Returns nullptr if not found
 */
Entity* FindEntityByName(const char* NameToFind) {
  for (auto& entity : EntityList) {
    if (strcmp(entity->Name, NameToFind) == 0) {
      return entity;
    }
  }
  return nullptr;
}

Entity* CreateEntity(const char* Name, const Vector2& position, GameTexture* Texture, Game& Game) {
  Entity* entity = new Entity(Name, position, Texture, Game);
  EntityList.push_back(entity);
  std::cout << "Added Entity to List\n";
  return entity;
}
Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture, Game& Game) {
  Player* player = new Player(Name, position, Texture, Game);
  EntityList.push_back(player);
  std::cout << "Added Player to List\n";
  return player;
}

bool DestroyEntity(Entity* Entity) {
  if (Entity == nullptr)
    return false;

  EntityList.erase(std::remove(EntityList.begin(), EntityList.end(), Entity), EntityList.end());

  delete Entity;
  Entity = nullptr;
  return true;
}
bool DestroyPlayer(Player* Player) {
  if (Player == nullptr)
    return false;

  EntityList.erase(std::remove(EntityList.begin(), EntityList.end(), Player), EntityList.end());

  delete Player;
  return true;
}

void DestroyAllEntities() {
  for (auto& entity : EntityList) {
    DestroyEntity(entity);
  }
  EntityList.clear();
}
}  // namespace World
