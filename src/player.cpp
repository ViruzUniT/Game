#include "../include/player.h"

#include <cmath>
#include <cstring>

#include "../include/math.h"

#define IDLE_ANIM_NAME "Idle"
#define WALK_ANIM_NAME "Walk"

Direction dir;
void Player::Move(Time& Time, Player& Player) {
  if (!dir.up && !dir.down && !dir.left && !dir.right) {
    if (strcmp(CurrentTexture.TextureName, IDLE_ANIM_NAME) != 0) {
      SwitchCurrentTexture(IDLE_ANIM_NAME);
    }
    return;
  }

  if (!SwitchCurrentTexture("Walk")) {
    return;
  }

  Vector2 Position = Player.GetPosition();

  // I will improve it eventually
  if (dir.up && dir.right) {
    Position.y -= sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
    Position.x += sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
  } else if (dir.up && dir.left) {
    Position.y -= sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
    Position.x -= sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
  } else if (dir.down && dir.left) {
    Position.y += sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
    Position.x -= sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
  } else if (dir.down && dir.right) {
    Position.y += sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
    Position.x += sqrt(square(Player.MovementSpeed) * 2) * Time.deltaTime * 100;
  } else if (dir.up) {
    Position.y -= Player.MovementSpeed * Time.deltaTime * 100;
  } else if (dir.down) {
    Position.y += Player.MovementSpeed * Time.deltaTime * 100;
  } else if (dir.right) {
    Position.x += Player.MovementSpeed * Time.deltaTime * 100;
  } else if (dir.left) {
    Position.x -= Player.MovementSpeed * Time.deltaTime * 100;
  }

  Player.SetPosition(Position);
}
