#include <iostream>
#include <ostream>

#include "../include/entity.h"
#include "../include/game.h"
#include "C:/SDL2-w64/include/SDL2/SDL.h"

void InitSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "SDL not working: " << SDL_GetError() << std::endl;
    return;
  }
  std::cout << "SDL working" << std::endl;
}

int main(int argc, char* argv[]) {
  Game Game("Game v0.1", 825, 480);
  Time Time(Game.GetWindow());
  RenderWindow window = Game.GetWindow();
  SDL_Texture* playerTexture = window.LoadTexture("F:/c++ game/sprites/Fighter/Idle.png");
  Entity Player(100, 100, playerTexture);

  while (Game.isRunning == true) {
    Time.StartMeasure();
    while (Time.accumulator >= Time.timeStep) {
      while (SDL_PollEvent(&Game.currentevent)) {
        if (Game.currentevent.type == SDL_QUIT) {
          Game.isRunning = false;
          break;
        }
      }
      Time.accumulator -= Time.timeStep;
    }
    window.Clear();
    window.Render(Player);
    window.Display();

    Time.SecondMeasure();
    Time.FrameLimitPause();
  }
  window.CleanUp();
  window.DestroyWindowAndRenderer();
  SDL_Quit();
  return 0;
}
