#pragma once

#include "SDL.h"
#include "player.h"
#include "renderer.h"
#include "time.h"

class GameTexture {
 public:
  GameTexture(SDL_Texture* texture, const SDL_Rect& currentFrame, const int& FrameOffset)
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

  GameTexture LoadTexture(const char* SpriteLocation, const Vector4& CurrentFrame, const int& FrameOffset, const RenderWindow& Window) {
    SDL_Texture* texture = window.LoadTexture(SpriteLocation);

    SDL_Rect currentFrame;
    currentFrame.x = CurrentFrame.x;
    currentFrame.y = CurrentFrame.y;
    currentFrame.h = CurrentFrame.h;
    currentFrame.w = CurrentFrame.w;
    return GameTexture(texture, currentFrame, FrameOffset);
  }

 private:
  const char* WindowName;
  int Width;
  int Height;

  RenderWindow window = RenderWindow(WindowName, Width, Height);

  SDL_Event currentevent;
};
