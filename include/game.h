#pragma once

#include <cstdint>
#include <iostream>
#include <ostream>

#include "SDL.h"
#include "renderer.h"

class Time {
 private:
  RenderWindow window;

  const int refreshRate = window.GetRefreshrate();
  const float frameDelay = 1000.0f / refreshRate;
  float currentTime = window.HiresTimeInSec();

  float newTime;
  int frameStart;
  int frameTicks;

 public:
  Time(RenderWindow& window) : window(window) {}

  const float timeStep = 0.01f;
  float deltaTime;
  float accumulator = 0;

  void StartMeasure();
  inline void SecondMeasure() { frameTicks = SDL_GetTicks() - frameStart; }
  inline void FrameLimitPause() {
    if (frameTicks < frameDelay) {
      SDL_Delay(frameDelay - frameTicks);
    }
  }

  inline void ShowFPS() { std::cout << 1 / deltaTime << std::endl; }
};

class Game {
 private:
  const char* WindowName;
  int Width;
  int Height;

  RenderWindow window = RenderWindow(WindowName, Width, Height);

 public:
  Game(const char* WindowName, int Width, int Height) : WindowName(WindowName), Width(Width), Height(Height) {}

  bool isRunning = true;
  SDL_Event currentevent;

  RenderWindow& GetWindow() { return window; }
};
