#pragma once
#include <iostream>

#include "renderer.h"

struct Time {
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

  void ShowFPS();

 private:
  RenderWindow window;

  const int refreshRate = window.GetRefreshrate();
  const float frameDelay = 1000.0f / refreshRate;
  float currentTime = window.HiresTimeInSec();

  float newTime;
  int frameStart;
  int frameTicks;
};
