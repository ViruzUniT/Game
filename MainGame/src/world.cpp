#include "../include/world.h"

using namespace World;

Game* CurrentGame;
void World::SetCurrentGame(Game* Game) { CurrentGame = Game; }
Game* World::GetCurrentGame() { return CurrentGame; }

std::vector<Object*> ObjectList;
std::vector<Object*> World::GetObjects() { return ObjectList; }

/*
 * Returns first Object with the given Name
 *
 * Returns nullptr if not found
 */
Object* World::FindObjectByName(const char* NameToFind) {
  for (auto& entity : ObjectList) {
    if (strcmp(entity->Name, NameToFind) == 0) {
      return entity;
    }
  }
  return nullptr;
}

Object* World::FindObjectByID(const size_t& Id) {
  if (ObjectList.size() - 1 <= Id) {
    return ObjectList[Id];
  }
  return nullptr;
}

Object* World::CreateObject(const char* Name, const Vector2& position, GameTexture* Texture) {
  Object* entity = new Object(Name, position, Texture);
  ObjectList.push_back(entity);
  std::cout << "Added Object to List\n";
  return entity;
}
Object* World::CreateObject(const char* Name, const Vector2& position) {
  Object* entity = new Object(Name, position);
  ObjectList.push_back(entity);
  std::cout << "Added Object to List\n";
  return entity;
}

Player* World::CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture) {
  Player* player = new Player(Name, position, Texture);
  ObjectList.push_back(player);
  std::cout << "Added Player to List\n";
  return player;
}
Player* World::CreatePlayer(const char* Name, const Vector2& position) {
  Player* player = new Player(Name, position);
  ObjectList.push_back(player);
  std::cout << "Added Player to List\n";
  return player;
}

bool World::DestroyObject(Object* Object) {
  if (Object == nullptr)
    return false;

  ObjectList.erase(std::remove(ObjectList.begin(), ObjectList.end(), Object), ObjectList.end());

  delete Object;
  Object = nullptr;
  return true;
}
bool World::DestroyPlayer(Player* Player) {
  if (Player == nullptr)
    return false;

  ObjectList.erase(std::remove(ObjectList.begin(), ObjectList.end(), Player), ObjectList.end());

  delete Player;
  return true;
}

void World::DestroyAllEntities() {
  for (auto& entity : ObjectList) {
    DestroyObject(entity);
  }
  ObjectList.clear();
}
