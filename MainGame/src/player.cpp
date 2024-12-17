#include "../include/player.h"

#include "../include/game.h"
#include "../include/math.h"
#include "../include/world.h"

void Player::Start() {
  AddTexture(LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 5));
  AddTexture(LoadTexture("Walk", "./sprites/Fighter/Walk.png", Vector4(46, 45, 24, 83), 104, 7));

  AddTexture(
      LoadTexture("Punch", "./sprites/Fighter/Attack_1.png", Vector4(38, 47, 53, 81), 92 - 17, 4));
  OnAnimationFinish.add(std::bind(&Player::StopPunch, this, std::placeholders::_1));

  std::cout << "SwitchCurrentTexture was " << SwitchCurrentTexture("Idle") << std::endl;

  RunTick = true;
}

void Player::Tick() { HandleSDLEvents(World::CurrentGame); }

void Player::Move() {
  if (!IsPunching) {
    if (!MovementDirection.up && !MovementDirection.down && !MovementDirection.left &&
        !MovementDirection.right) {
      SwitchCurrentTexture("Idle");
      return;
    }
    SwitchCurrentTexture("Walk");

  } else {
    SwitchCurrentTexture("Punch");
  }

  Vector2 Position = GetPosition();

  // I will improve it eventually
  if (MovementDirection.up) {
    Position.y -= MovementSpeed * MovementSpeedMultiplier;
  }
  if (MovementDirection.down) {
    Position.y += MovementSpeed * MovementSpeedMultiplier;
  }
  if (MovementDirection.right) {
    Position.x += MovementSpeed * MovementSpeedMultiplier;
  }
  if (MovementDirection.left) {
    Position.x -= MovementSpeed * MovementSpeedMultiplier;
  }

  SetPosition(Position);
}

void Player::Punch() { IsPunching = true; }
void Player::StopPunch(GameTexture& Texture) {
  // std::cout << "Called Stop Punch with name: " << Texture.TextureName << std::endl;
  if (Texture.TextureName == "Punch") {
    IsPunching = false;
  }
}

void Player::HandleSDLEvents(Game* Game) {
  while (SDL_PollEvent(&CurrentEvent)) {
    switch (CurrentEvent.type) {
      case SDL_QUIT:
        Game->StopGame();
        break;
      case SDL_KEYDOWN:
        switch (CurrentEvent.key.keysym.sym) {
          case SDLK_w:
            MovementDirection.up = true;
            break;
          case SDLK_a:
            MovementDirection.left = true;
            break;
          case SDLK_s:
            MovementDirection.down = true;
            break;
          case SDLK_d:
            MovementDirection.right = true;
            break;
          case SDLK_SPACE:
            Punch();
            break;
          case SDLK_F3:
            Game->StopGame();
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch (CurrentEvent.key.keysym.sym) {
          case SDLK_w:
            MovementDirection.up = false;
            break;
          case SDLK_a:
            MovementDirection.left = false;
            break;
          case SDLK_s:
            MovementDirection.down = false;
            break;
          case SDLK_d:
            MovementDirection.right = false;
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }

  Move();
  PlayAnimation();
}
