#include "entity.h"

class Player : public Entity {
public:
  Player(Vector2 position, SDL_Texture* texture, Vector4 currentFrame) : Position(position), Texture(texture) {
    CurrentFrame.x = currentFrame.x;
    CurrentFrame.y = currentFrame.y;
    CurrentFrame.w = currentFrame.w;
    CurrentFrame.h = currentFrame.h;
  }
  float MovementSpeed = 10.0f; 
  
private:
  Vector2 Position;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
};
