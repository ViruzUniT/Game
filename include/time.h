#pragma once
#include <iostream>

#include "renderer.h"

struct Time {
 public:
  // Time(RenderWindow& window) : window(window) {}
  Time() {}
  inline void SetWindow(RenderWindow& Window) { window = Window; }

  const float timeStep = 0.01f;
  double deltaTime;
  double accumulator;

  void StartMeasure();
  inline void EndMeasure() { frameTicks = SDL_GetTicks() - frameStart; }
  inline void FrameLimitPause() {
    if (frameTicks < frameDelay) {
      SDL_Delay(frameDelay - frameTicks);
    }
  }

  void ShowFPS();

 private:
  RenderWindow window;

  const int refreshRate = window.GetRefreshrate();
  const double frameDelay = 1000.0f / refreshRate;
  double currentTime = window.HiresTimeInSec();

  double newTime;
  int frameStart;
  int frameTicks;
};
