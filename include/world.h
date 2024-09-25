#include "player.h"
namespace World {
Entity* FindEntityByName(const char* NameToFind);

Entity* CreateEntity(const Vector2& position, GameTexture* Texture, Game& Game);
Player* CreatePlayer(const Vector2& position, GameTexture* Texture, Game& Game);

bool DestroyEntity(Entity* Entity);
bool DestroyPlayer(Player* Player);

void DestroyAllEntities();
}  // namespace World
