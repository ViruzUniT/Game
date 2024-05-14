#include "../include/time.h"

#include <iostream>

void Time::StartMeasure() {
  frameStart = SDL_GetTicks();

  newTime = window.HiresTimeInSec();
  deltaTime = newTime - currentTime;
  currentTime = newTime;

  accumulator += deltaTime;
}

void Time::ShowFPS() {
  static float fps_timer = 0.0f;
  static int fps_counter = 0;

  fps_timer += deltaTime;
  fps_counter += 1;

  if (fps_timer >= 1.0f) {
    std::cout << fps_counter << "\n";
    fps_counter = 0;
    fps_timer = 0.0f;
  }
}
