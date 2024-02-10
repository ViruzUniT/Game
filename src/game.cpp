#include "../include/game.h"

void Game::HandleSDLEvents(Time& Time) {
  while (SDL_PollEvent(&currentevent)) {
    switch (currentevent.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:
        std::cout << "Key Pressed" << std::endl;

        switch (currentevent.key.keysym.sym) {
          case SDLK_RIGHT:
            std::cout << "Right was pressed" << std::endl;
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
