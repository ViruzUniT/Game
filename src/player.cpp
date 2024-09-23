#include "../include/player.h"

#include <cmath>
#include <cstring>

#include "../include/math.h"

#define IDLE_ANIM_NAME "Idle"
#define WALK_ANIM_NAME "Walk"

void Player::Move(Time& Time, Player& Player) {
  if (!Dir.up && !Dir.down && !Dir.left && !Dir.right) {
    if (strcmp(CurrentTexture.TextureName, IDLE_ANIM_NAME) != 0) {
      SwitchCurrentTexture(IDLE_ANIM_NAME);
    }
    return;
  }

  if (!SwitchCurrentTexture(WALK_ANIM_NAME)) {
    return;
  }

  Vector2 Position = Player.GetPosition();

  // I will improve it eventually
  if (Dir.up && Dir.right) {
    Position.y -= sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
    Position.x += sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
  } else if (Dir.up && Dir.left) {
    Position.y -= sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
    Position.x -= sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
  } else if (Dir.down && Dir.left) {
    Position.y += sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
    Position.x -= sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
  } else if (Dir.down && Dir.right) {
    Position.y += sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
    Position.x += sqrt(square(Player.MovementSpeed) * 2) * Player.MovementSpeedMultiplier;
  } else if (Dir.up) {
    Position.y -= Player.MovementSpeed * Player.MovementSpeedMultiplier;
  } else if (Dir.down) {
    Position.y += Player.MovementSpeed * Player.MovementSpeedMultiplier;
  } else if (Dir.right) {
    Position.x += Player.MovementSpeed * Player.MovementSpeedMultiplier;
  } else if (Dir.left) {
    Position.x -= Player.MovementSpeed * Player.MovementSpeedMultiplier;
  }

  Player.SetPosition(Position);
}
