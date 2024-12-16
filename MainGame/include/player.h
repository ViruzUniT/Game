#pragma once
#include "object.h"
#include "texture.h"
#include "time.h"

struct Direction {
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
};

class Player : public Object {
 public:
  Player(const char* PlayerName, const Vector2& position, GameTexture* texture)
      : Object(PlayerName, position, texture), IsPunching(false) {}
  ~Player() {}

  void Start() override;
  void Tick() override;

  void Move();
  void Punch();
  void StopPunch(GameTexture& Texture);

  void HandleSDLEvents(Game* Game);

  Direction MovementDirection;
  float MovementSpeed = 5.0f;
  float MovementSpeedMultiplier = 1.0f;

 private:
  SDL_Event CurrentEvent;
  bool IsPunching;
};
