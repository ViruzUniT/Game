#include "../include/game.h"

struct Direction {
 public:
  bool up;
  bool down;
  bool left;
  bool right;
};

Direction dir;
static void MovePlayer(Time& Time, Player& Player) {
  if (!dir.up && !dir.down && !dir.left && !dir.right) {
    return;
  }
  Vector2 Position = Player.GetPosition();
  if (dir.up)
    Position.y += Player.MovementSpeed;
  if (dir.down)
    Position.y -= Player.MovementSpeed;
  if (dir.left)
    Position.x -= Player.MovementSpeed;
  if (dir.right)
    Position.x += Player.MovementSpeed;
  Player.SetPosition(Position);
}

void Game::HandleSDLEvents(Time& Time, Player& Player) {
  while (SDL_PollEvent(&currentevent)) {
    switch (currentevent.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:
        std::cout << "Key Pressed\n";

        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            std::cout << "W was pressed\n";
            dir.up = true;
            //MovePlayer(Time, Player);
            break;
          case SDLK_a:
            std::cout << "A was pressed\n";
            dir.left = true;
            //MovePlayer(Time, Player);
            break;
          case SDLK_s:
            std::cout << "S was pressed\n";
            dir.down = true;
            //MovePlayer(Time, Player);
            break;
          case SDLK_d:
            std::cout << "D was pressed\n";
            dir.right = true;
            //MovePlayer(Time, Player);
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            std::cout << "W was released\n";
            dir.up = false;
            break;
          case SDLK_a:
            std::cout << "A was released\n";
            dir.left = false;
            break;
          case SDLK_s:
            std::cout << "S was released\n";
            dir.down = false;
            break;
          case SDLK_d:
            std::cout << "D was released\n";
            dir.right = false;
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
  MovePlayer(Time, Player);
  Time.accumulator -= Time.timeStep;
}
