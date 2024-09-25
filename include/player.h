#pragma once
#include "entity.h"
#include "texture.h"
#include "time.h"

struct Direction {
 public:
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
};

class Player : public Entity {
 public:
  Player(const char* PlayerName, const Vector2& position, GameTexture* texture, Game& Game) : Entity(PlayerName, position, texture, Game) {}
  ~Player() {}
  float MovementSpeed = 5.0f;
  float MovementSpeedMultiplier = 1.0f;

  void Move(Time& Time);
  void Punch();

  Direction Dir;

 private:
};
