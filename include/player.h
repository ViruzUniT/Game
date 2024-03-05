#include "entity.h"

class Player : public Entity {
 public:
  Player(Vector2 position, GameTexture texture) : Entity(position, texture) {}
  float MovementSpeed = 5.0f;

 private:
};
