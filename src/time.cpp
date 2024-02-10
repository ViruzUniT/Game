#include "../include/time.h"

void Time::StartMeasure() {
  frameStart = SDL_GetTicks();

  newTime = window.HiresTimeInSec();
  deltaTime = newTime - currentTime;
  currentTime = window.HiresTimeInSec();

  accumulator += deltaTime;
}
