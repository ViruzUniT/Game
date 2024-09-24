#include "../include/world.h"
namespace World {
std::vector<Entity*> EntityList;
Entity* CreateEntity(const Vector2& position, GameTexture& Texture, Game& Game) {
  Entity* entity = new Entity(position, Texture, Game);
  EntityList.push_back(entity);
  std::cout << "Added Entity to List\n";
  return entity;
}
Player* CreatePlayer(const Vector2& position, GameTexture& Texture, Game& Game) {
  Player* player = new Player(position, Texture, Game);
  EntityList.push_back(player);
  std::cout << "Added Entity to List\n";
  return player;
}

bool DestroyEntity(Entity* Entity) {
  if (Entity == nullptr)
    return false;

  delete Entity;
  return true;
}
bool DestroyPlayer(Player* Player) {
  if (Player == nullptr)
    return false;

  delete Player;
  return true;
}
}  // namespace World
