#include <vector>

#include "../include/game.h"
#include "../include/player.h"
#include "../include/timer.h"

Game Game("Game v0.1", 825, 480);
Time Time(Game.GetWindow());
std::vector<Entity*> EntityList;

int main(int argc, char* argv[]) {
  Timer* startupTimer = new Timer();

  RenderWindow window = Game.GetWindow();

  GameTexture playerIdleTexture = Game.LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 5, window);
  Player Player(Vector2(100, 100), playerIdleTexture);
  Player.AddTexture(Game.LoadTexture("Walk", "./sprites/Fighter/Walk.png", Vector4(46, 45, 24, 83), 104, 7, window));

  delete startupTimer;

  while (Game.isRunning == true) {
    Time.StartMeasure();
    while (Time.accumulator >= Time.timeStep) {
      Game.HandleSDLEvents(Time, Player);
      Time.accumulator -= Time.timeStep;
    }

    window.Clear();
    window.Render(Player);
    window.Display();

    Time.EndMeasure();
    Time.FrameLimitPause();
    Time.ShowFPS();
  }
  window.CleanUp();
  window.DestroyWindowAndRenderer();
  SDL_Quit();
  return 0;
}
