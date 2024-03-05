#include <chrono>
#include <iostream>
#include <ostream>

#include "../include/entity.h"
#include "../include/game.h"
#include "C:/SDL2-w64/include/SDL2/SDL.h"

struct Timer {
 public:
  Timer() { m_StartTimePoint = std::chrono::high_resolution_clock::now(); }
  ~Timer() { Stop(); }
  void Stop() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
    auto duration = end - start;
    double ms = duration * 0.001;
    double s = duration / 1000000.0;
    std::cout << s << " s (" << ms << " ms, " << duration << " us)\n";
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};

int main(int argc, char* argv[]) {
  Timer* startupTimer = new Timer();
  Game Game("Game v0.1", 825, 480);
  Time Time(Game.GetWindow());

  RenderWindow window = Game.GetWindow();

  // SDL_Texture* playerTexture = window.LoadTexture("./sprites/Fighter/Idle.png");
  GameTexture playerTexture = Game.LoadTexture("./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, window)
                                  Player Player(Vector2(100, 100), playerTexture, Vector4(46, 47, 30, 81));
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
