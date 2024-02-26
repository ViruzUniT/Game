#include "../include/game.h"

static 
static void MovePlayer(Player& Player) {
  
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
            break;
          case SDLK_a:
            std::cout << "A was pressed\n";
            break;
          case SDLK_s:
            std::cout << "S was pressed\n";
            break;
          case SDLK_d:
            std::cout << "D was pressed\n";
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            std::cout << "W was released\n";
            break;
          case SDLK_a:
            std::cout << "A was released\n";
            break;
          case SDLK_s:
            std::cout << "S was released\n";
            break;
          case SDLK_d:
            std::cout << "D was released\n";
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
  Time.accumulator -= Time.timeStep;
}
