#pragma once

#include "SDL.h"
#include "math.h"
#include "player.h"
#include "renderer.h"
#include "time.h"

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height) : WindowName(WindowName), Width(Width), Height(Height) {}
  ~Game() { delete WindowName; }
  bool isRunning = true;

  RenderWindow& GetWindow() { return window; }

  void HandleSDLEvents(Time& Time, Player& Player);

  GameTexture LoadTexture(const char* TextureName, const char* SpriteLocation, Vector4 CurrentFrame, int FrameOffset, int Frames,
      RenderWindow Window);

 private:
  const char* WindowName;
  int Width;
  int Height;

  RenderWindow window = RenderWindow(WindowName, Width, Height);

  SDL_Event currentevent;
};
