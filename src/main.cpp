#include <iostream>
#include <ostream>

#include "../include/entity.h"
#include "../include/renderer.h"
#include "C:/SDL2-w64/include/SDL2/SDL.h"

void InitSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "SDL not working: " << SDL_GetError() << std::endl;
    return;
  }
  std::cout << "SDL working" << std::endl;
}

int main(int argc, char* argv[]) {
  RenderWindow window("Game v0.1", 852, 480);

  bool isRunning = true;
  SDL_Event currentevent;

  const int refreshRate = window.GetRefreshrate();
  const float frameDelay = 1000.0f / refreshRate;

  float newTime;
  float deltaTime;
  float currentTime = window.HiresTimeInSec();
  int frameStart;
  int frameTicks;
  constexpr float timeStep = 0.01f;
  float accumulator = 0;

  SDL_Texture* playerTexture = window.LoadTexture("F:/c++ game/sprites/Fighter/Idle.png");
  Entity Player(100, 100, playerTexture);

  while (isRunning == true) {
    frameStart = SDL_GetTicks();

    newTime = window.HiresTimeInSec();
    deltaTime = newTime - currentTime;
    currentTime = window.HiresTimeInSec();

    accumulator += deltaTime;
    while (accumulator >= timeStep) {
      while (SDL_PollEvent(&currentevent)) {
        if (currentevent.type == SDL_QUIT) {
          isRunning = false;
          break;
        }
      }
      accumulator -= timeStep;
    }
    window.Clear();
    window.Render(Player);
    window.Display();

    frameTicks = SDL_GetTicks() - frameStart;
    if (frameTicks < frameDelay) {
      SDL_Delay(frameDelay - frameTicks);
    }
    isRunning = false;
  }
  window.CleanUp();
  window.DestroyWindowAndRenderer();
  SDL_Quit();
  return 0;
}
