#pragma once

#include "SDL.h"
#include "math.h"
#include "player.h"
#include "renderer.h"
#include "time.h"
#include "timer.h"

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height) : WindowName(WindowName), Width(Width), Height(Height) {
    isRunning = true;
    this->time = new Time(GetWindow());
    std::vector<Entity*> EntityList;
    Timer* startupTimer = new Timer();

    RenderWindow window = GetWindow();

    delete startupTimer;
  }
  ~Game() { delete WindowName; }

  void RunGame() {
    GameTexture playerIdleTexture = LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 5, window);
    Player Player(Vector2(100, 100), playerIdleTexture);
    Player.AddTexture(LoadTexture("Walk", "./sprites/Fighter/Walk.png", Vector4(46, 45, 24, 83), 104, 7, window));

    while (isRunning == true) {
      time->StartMeasure();
      while (time->accumulator >= time->timeStep) {
        HandleSDLEvents(*time, Player);
        time->accumulator -= time->timeStep;
      }

      window.Clear();
      window.Render(Player);
      window.Display();

      time->EndMeasure();
      time->FrameLimitPause();
      time->ShowFPS();
    }
    window.CleanUp();
    window.DestroyWindowAndRenderer();
    SDL_Quit();
  }

  inline bool IsGameRunning() { return isRunning; }
  RenderWindow& GetWindow() { return window; }

  void HandleSDLEvents(Time& Time, Player& Player);

  GameTexture LoadTexture(const char* TextureName, const char* SpriteLocation, Vector4 CurrentFrame, int FrameOffset, int Frames,
      RenderWindow Window);

  Time* time;
  std::vector<Entity*> EntityList;

 private:
  bool isRunning;

  const char* WindowName;
  int Width;
  int Height;

  RenderWindow window = RenderWindow(WindowName, Width, Height);

  SDL_Event currentevent;
};
