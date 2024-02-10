#pragma once

#include <cstdint>
#include <iostream>
#include <ostream>

#include "SDL.h"
#include "renderer.h"
#include "time.h"

struct Game {
  Game(const char* WindowName, int Width, int Height) : WindowName(WindowName), Width(Width), Height(Height) {}

  bool isRunning = true;
  SDL_Event currentevent;

  RenderWindow& GetWindow() { return window; }

 private:
  const char* WindowName;
  int Width;
  int Height;

  RenderWindow window = RenderWindow(WindowName, Width, Height);
};
