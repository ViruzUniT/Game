#include "../include/player.h"

#include <cstring>

#include "../include/math.h"

#define IDLE_ANIM_NAME "Idle"
#define WALK_ANIM_NAME "Walk"

void Player::Move(Time& Time) {
  if (!Dir.up && !Dir.down && !Dir.left && !Dir.right) {
    if (strcmp(CurrentTexture.TextureName, IDLE_ANIM_NAME) != 0) {
      SwitchCurrentTexture(IDLE_ANIM_NAME);
    }
    return;
  }

  if (strcmp(CurrentTexture.TextureName, WALK_ANIM_NAME) != 0) {
    if (!SwitchCurrentTexture(WALK_ANIM_NAME)) {
      return;
    }
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
