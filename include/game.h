#pragma once

#include <cstdint>
#include <iostream>
#include <ostream>

#include "SDL.h"
#include "entity.h"
#include "player.h"
#include "renderer.h"
#include "time.h"

struct Texture {
public:
  Texture(SDL_Texture* texture, const SDL_Rect& currentFrame, const int& FrameOffset)
  : texture(texture), CurrentFrame(currentFrame), frameOffset(FrameOffset) {}
  SDL_Texture* texture;
  SDL_Rect CurrentFrame;
  int frameOffset;
};

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height) : WindowName(WindowName), Width(Width), Height(Height) {}
  ~Game() { delete WindowName; }
  bool isRunning = true;

  RenderWindow& GetWindow() { return window; }

  void HandleSDLEvents(Time& Time, Player& Player);

  Texture LoadTexture(const char* SpriteLocation, const SDL_Rect& CurrentFrame, const int& FrameOffset,
      const RenderWindow& Window);

 private:
  const char* WindowName;
  int Width;
  int Height;

  RenderWindow window = RenderWindow(WindowName, Width, Height);

  SDL_Event currentevent;
};

