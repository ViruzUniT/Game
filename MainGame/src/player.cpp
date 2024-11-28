#include "../include/player.h"

#include <cstring>

#include "../include/math.h"

void Player::Move() {
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

void Player::HandleSDLEvents(Game* Game) {
  while (SDL_PollEvent(&currentevent)) {
    switch (currentevent.type) {
      case SDL_QUIT:
        Game->StopGame();
        break;
      case SDL_KEYDOWN:
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            Dir.up = true;
            break;
          case SDLK_a:
            Dir.left = true;
            break;
          case SDLK_s:
            Dir.down = true;
            break;
          case SDLK_d:
            Dir.right = true;
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
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            Dir.up = false;
            break;
          case SDLK_a:
            Dir.left = false;
            break;
          case SDLK_s:
            Dir.down = false;
            break;
          case SDLK_d:
            Dir.right = false;
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
