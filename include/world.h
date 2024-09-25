#include "player.h"
namespace World {
std::vector<Entity*> GetEntities();
Entity* FindEntityByName(const char* NameToFind);

Entity* CreateEntity(const char* Name, const Vector2& position, GameTexture* Texture, Game& Game);
Player* CreatePlayer(const char* Name, const Vector2& position, GameTexture* Texture, Game& Game);

bool DestroyEntity(Entity* Entity);
bool DestroyPlayer(Player* Player);

void DestroyAllEntities();
}  // namespace World
