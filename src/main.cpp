#include "../include/game.h"
#include "../include/player.h"
#include "../include/timer.h"
#include "C:/SDL2-w64/include/SDL2/SDL.h"

int main(int argc, char* argv[]) {
  Timer* startupTimer = new Timer();
  Game Game("Game v0.1", 825, 480);
  Time Time(Game.GetWindow());

  RenderWindow window = Game.GetWindow();

  // SDL_Texture* playerTexture = window.LoadTexture("./sprites/Fighter/Idle.png");
  GameTexture playerTexture = Game.LoadTexture("./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, window);
  Player Player(Vector2(100, 100), playerTexture);
  delete startupTimer;
  while (Game.isRunning == true) {
    Time.StartMeasure();
    while (Time.accumulator >= Time.timeStep) {
      Game.HandleSDLEvents(Time, Player);
    }

    window.Clear();
    window.Render(Player);
    window.Display();

    Time.SecondMeasure();
    Time.FrameLimitPause();
    Time.ShowFPS();
  }
  window.CleanUp();
  window.DestroyWindowAndRenderer();
  SDL_Quit();
  return 0;
}
