#include "entity.h"

class Player : public Entity {
public:
  Player(Vector2 position, GameTexture texture, Vector4 currentFrame): Entity(position, texture, currentFrame){}
  float MovementSpeed = 5.0f; 
  
private:
};
