#include "../include/game.h"

void Game::HandleSDLEvents(Time& Time) {
  while (SDL_PollEvent(&currentevent)) {
    switch (currentevent.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:
        std::cout << "Key Pressed: " << currentevent.key.keysym.sym << " Right: " << SDLK_RIGHT << "\n";

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
      default:
        break;
    }
  }
  Time.accumulator -= Time.timeStep;
}
