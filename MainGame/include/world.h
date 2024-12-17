#pragma once
#include <iostream>

#include "game.h"
#include "player.h"

namespace World {
void SetCurrentGame(Game* Game);
Game* GetCurrentGame();
std::vector<Object*>& GetObjects();
Object* FindObjectByName(const char* NameToFind);
Object* FindObjectByID(const size_t& Id);

Object* CreateObject(const char* Name, const Vector2& position);
Object* CreateObject(const char* Name, const Vector2& position, GameTexture* Texture);
Player* CreatePlayer(const char* Name, const Vector2& position);
Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture);

bool DestroyObject(Object* Object);
bool DestroyPlayer(Player* Player);

void DestroyAllEntities();
}  // namespace World
