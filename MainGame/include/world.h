#include "player.h"
namespace World {
std::vector<Object*> GetEntities();
Object* FindEntityByName(const char* NameToFind);

Object* CreateEntity(const char* Name, const Vector2& position, GameTexture* Texture,
    Game& Game);
Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture,
    Game& Game);

bool DestroyEntity(Object* Entity);
bool DestroyPlayer(Player* Player);

void DestroyAllEntities();
}  // namespace World
