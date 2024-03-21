#include "../include/player.h"

#include <cstring>

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

  if (dir.up)
    Position.y -= Player.MovementSpeed * Time.deltaTime * 100;
  if (dir.down)
    Position.y += Player.MovementSpeed * Time.deltaTime * 100;
  if (dir.left)
    Position.x -= Player.MovementSpeed * Time.deltaTime * 100;
  if (dir.right)
    Position.x += Player.MovementSpeed * Time.deltaTime * 100;
  Player.SetPosition(Position);
}
