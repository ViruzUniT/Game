#pragma once

#include "SDL.h"
#include "math.h"
#include "renderer.h"
#include "texture.h"
#include "time.h"
#include "timer.h"

class Player;

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height)
      : WindowName(WindowName),
        Width(Width),
        Height(Height),
        Window(RenderWindow(WindowName, Width, Height)) {}
  ~Game() {}

  void StartGame();
  void RunGame();
  void StopGame() { isRunning = false; }

  inline bool IsGameRunning() { return isRunning; }
  RenderWindow& GetWindow() { return Window; }

  GameTexture* LoadTexture(const char* TextureName, const char* SpriteLocation,
      const Vector4& CurrentFrame, const int& FrameOffset, const int& Frames,
      RenderWindow& Window);

  Time Timing;

 private:
  bool isRunning;

  const char* WindowName;
  int Width;
  int Height;

  RenderWindow Window;
};
