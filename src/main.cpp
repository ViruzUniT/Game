#include "../include/game.h"
#include "../include/player.h"
#include "../include/timer.h"
#include "C:/SDL2-w64/include/SDL2/SDL.h"

Game Game("Game v0.1", 825, 480);
Time Time(Game.GetWindow());

int main(int argc, char* argv[]) {
  Timer* startupTimer = new Timer();

  RenderWindow window = Game.GetWindow();

  GameTexture playerIdleTexture = Game.LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 3, window);
  Player Player(Vector2(100, 100), playerIdleTexture);
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
