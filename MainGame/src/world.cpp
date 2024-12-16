#include "../include/world.h"

#include "../include/player.h"

namespace World {
Game* CurrentGame;
std::vector<Object*> ObjectList;
std::vector<Object*> GetObjects() { return ObjectList; }

/*
 * Returns first Object with the given Name
 *
 * Returns nullptr if not found
 */
Object* FindObjectByName(const char* NameToFind) {
  for (auto& entity : ObjectList) {
    if (strcmp(entity->Name, NameToFind) == 0) {
      return entity;
    }
  }
  return nullptr;
}

Object* FindObjectByID(const size_t& Id) {
  if (ObjectList.size() - 1 <= Id) {
    return ObjectList[Id];
  }
  return nullptr;
}

Object* CreateObject(const char* Name, const Vector2& position, GameTexture* Texture) {
  Object* entity = new Object(Name, position, Texture);
  ObjectList.push_back(entity);
  std::cout << "Added Object to List\n";
  return entity;
}
Object* CreateObject(const char* Name, const Vector2& position) {
  Object* entity = new Object(Name, position);
  ObjectList.push_back(entity);
  std::cout << "Added Object to List\n";
  return entity;
}

Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture) {
  Player* player = new Player(Name, position, Texture);
  ObjectList.push_back(player);
  std::cout << "Added Player to List\n";
  return player;
}
Player* CreatePlayer(const char* Name, const Vector2& position) {
  Player* player = new Player(Name, position);
  ObjectList.push_back(player);
  std::cout << "Added Player to List\n";
  return player;
}

bool DestroyObject(Object* Object) {
  if (Object == nullptr)
    return false;

  ObjectList.erase(std::remove(ObjectList.begin(), ObjectList.end(), Object), ObjectList.end());

  delete Object;
  Object = nullptr;
  return true;
}
bool DestroyPlayer(Player* Player) {
  if (Player == nullptr)
    return false;

  ObjectList.erase(std::remove(ObjectList.begin(), ObjectList.end(), Player), ObjectList.end());

  delete Player;
  return true;
}

void DestroyAllEntities() {
  for (auto& entity : ObjectList) {
    DestroyObject(entity);
  }
  ObjectList.clear();
}
}  // namespace World
