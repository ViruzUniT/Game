#pragma once

#include <iostream>

#include "player.h"

namespace World {
std::vector<Object*> GetObjects();
Object* FindObjectByName(const char* NameToFind);
Object* FindObjectByID(const size_t& Id);

Object* CreateObject(const char* Name, const Vector2& position, GameTexture* Texture,
    Game& Game);
Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture,
    Game& Game);

bool DestroyObject(Object* Object);
bool DestroyPlayer(Player* Player);

void DestroyAllEntities();
}  // namespace World
