#include "../include/player.h"

#include <cstring>

#include "../include/math.h"

void Player::Move() {
  if (!IsPunching) {
    if (!MovementDirection.up && !MovementDirection.down && !MovementDirection.left &&
        !MovementDirection.right) {
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
  if (strcmp(Texture.TextureName, "Punch") == 0) {
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
