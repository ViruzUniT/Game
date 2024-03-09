#include "../include/game.h"

#include "../include/player.h"

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
    Position.y -= Player.MovementSpeed * Time.deltaTime * 100;
  if (dir.down)
    Position.y += Player.MovementSpeed * Time.deltaTime * 100;
  if (dir.left)
    Position.x -= Player.MovementSpeed * Time.deltaTime * 100;
  if (dir.right)
    Position.x += Player.MovementSpeed * Time.deltaTime * 100;
  Player.SetPosition(Position);
}

void Game::HandleSDLEvents(Time& Time, Player& Player) {
  while (SDL_PollEvent(&currentevent)) {
    switch (currentevent.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:

        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            dir.up = true;
            break;
          case SDLK_a:
            dir.left = true;
            break;
          case SDLK_s:
            dir.down = true;
            break;
          case SDLK_d:
            dir.right = true;
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            dir.up = false;
            break;
          case SDLK_a:
            dir.left = false;
            break;
          case SDLK_s:
            dir.down = false;
            break;
          case SDLK_d:
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
  Player.PlayAnimation();
  MovePlayer(Time, Player);
  Time.accumulator -= Time.timeStep;
}

GameTexture Game::LoadTexture(const char* TextureName, const char* SpriteLocation, Vector4 CurrentFrame, int FrameOffset, int Frames,
    RenderWindow Window) {
  SDL_Texture* texture = window.LoadTexture(SpriteLocation);

  SDL_Rect currentFrame;
  currentFrame.x = CurrentFrame.x;
  currentFrame.y = CurrentFrame.y;
  currentFrame.h = CurrentFrame.h;
  currentFrame.w = CurrentFrame.w;
  return GameTexture(TextureName, texture, currentFrame, FrameOffset, Frames);
}
