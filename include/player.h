#include "entity.h"

class Player : public Entity {
public:
  Player(Vector2 position, SDL_Texture* texture, Vector4 currentFrame): Entity(position, texture, currentFrame){}
  float MovementSpeed = 10.0f; 
  
private:
};
