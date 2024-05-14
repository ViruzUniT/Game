#pragma once
#include "entity.h"
#include "texture.h"
#include "time.h"

struct Direction {
 public:
  bool up;
  bool down;
  bool left;
  bool right;
};

class Player : public Entity {
 public:
  Player(Vector2 position, GameTexture texture) : Entity(position, texture) {}
  float MovementSpeed = 5.0f;
  float MovementSpeedMultiplier = 1.0f;

  void Move(Time& Time, Player& Player);

 private:
};
