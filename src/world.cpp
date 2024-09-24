#include "../include/world.h"
namespace World {
std::vector<Entity*> EntityList;
Entity* CreateEntity(const char* Name, const Vector2& position, GameTexture& Texture, Game& Game) {
  Entity* entity = new Entity(Name, position, Texture, Game);
  EntityList.push_back(entity);
  std::cout << "Added Entity to List\n";
  return entity;
}
Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture& Texture, Game& Game) {
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
  return true;
}
bool DestroyPlayer(Entity* Player) {
  if (Player == nullptr)
    return false;

  EntityList.erase(std::remove(EntityList.begin(), EntityList.end(), Player), EntityList.end());

  delete Player;
  return true;
}
}  // namespace World
