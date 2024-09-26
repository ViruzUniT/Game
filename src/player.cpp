#include "../include/player.h"

#include <cstring>

#include "../include/math.h"

void Player::Move(Time& Time) {
  if (!IsPunching) {
    if (!Dir.up && !Dir.down && !Dir.left && !Dir.right) {
      if (strcmp(CurrentTexture.TextureName, "Idle") != 0) {
        SwitchCurrentTexture("Idle");
      }
      return;
    }

    if (strcmp(CurrentTexture.TextureName, "Walk") != 0) {
      if (!SwitchCurrentTexture("Walk")) {
        return;
      }
    }
  } else {
    if (strcmp(CurrentTexture.TextureName, "Punch") != 0)
      SwitchCurrentTexture("Punch");
  }

  Vector2 Position = GetPosition();

  // I will improve it eventually
  if (Dir.up) {
    Position.y -= MovementSpeed * MovementSpeedMultiplier;
  }
  if (Dir.down) {
    Position.y += MovementSpeed * MovementSpeedMultiplier;
  }
  if (Dir.right) {
    Position.x += MovementSpeed * MovementSpeedMultiplier;
  }
  if (Dir.left) {
    Position.x -= MovementSpeed * MovementSpeedMultiplier;
  }

  SetPosition(Position);
}

void Player::Punch() { IsPunching = true; }
void Player::StopPunch(GameTexture& Texture) {
  // std::cout << "Called Stop Punch with name: " << Texture.TextureName << std::endl;
  if (strcmp(Texture.TextureName, "Punch") == 0) {
    IsPunching = false;
  }
}
