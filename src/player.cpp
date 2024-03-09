#include "../include/player.h"

Direction dir;
void Player::Move(Time& Time, Player& Player) {
  if (!dir.up && !dir.down && !dir.left && !dir.right) {
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
