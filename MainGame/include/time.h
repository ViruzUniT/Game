#pragma once
#include <iostream>

#include "renderer.h"

struct Time {
 public:
  // Time(RenderWindow& window) : window(window) {}
  Time() {}
  inline void SetWindow(RenderWindow* Window) {
    window = Window;
    refreshRate = window->GetRefreshrate();
    frameDelay = 1000.0f / refreshRate;
    currentTime = window->HiresTimeInSec();
  }

  const float timeStep = 0.01f;
  double deltaTime;
  double accumulator;

  void StartMeasure();
  inline void EndMeasure() { frameTicks = SDL_GetTicks() - frameStart; }
  inline void FrameLimitPause() {
    if (frameTicks < frameDelay)
      SDL_Delay(frameDelay - frameTicks);
  }

  void ShowFPS();

 private:
  RenderWindow* window;

  int refreshRate;
  double frameDelay;
  double currentTime;

  double newTime;
  int frameStart;
  int frameTicks;
};
