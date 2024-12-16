#pragma once
#include "SDL.h"
#include "math.h"
#include "renderer.h"
#include "texture.h"
#include "time.h"
#include "timer.h"
#include "world.h"

class Player;

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height)
      : WindowName(WindowName),
        Width(Width),
        Height(Height),
        Window(RenderWindow(WindowName, Width, Height)) {
    World::CurrentGame = this;
  }
  ~Game() {}

  void StartGame();
  void RunGame();
  inline void StopGame() { isRunning = false; }

  inline bool IsGameRunning() { return isRunning; }
  RenderWindow& GetWindow() { return Window; }

  GameTexture* LoadTexture(const char* TextureName, const char* SpriteLocation,
      const Vector4& CurrentFrame, const int& FrameOffset, const int& Frames,
      RenderWindow& Window);

  void ObjectsRunStart();
  void ObjectsRunTick();

  Time Timing;

 private:
  bool isRunning;

  const char* WindowName;
  int Width;
  int Height;

  RenderWindow Window;
};
