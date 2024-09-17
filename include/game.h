#pragma once

#include "SDL.h"
#include "math.h"
// #include "player.h"
#include "renderer.h"
#include "texture.h"
#include "time.h"
#include "timer.h"

class Player;

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height) : WindowName(WindowName), Width(Width), Height(Height) {
    isRunning = true;
    this->Time = new struct Time(Window);
    std::vector<Entity*> EntityList;
    Timer* startupTimer = new Timer();

    delete startupTimer;
  }
  ~Game() {
    delete Time;
    delete WindowName;
  }

  void RunGame();

  inline bool IsGameRunning() { return isRunning; }
  RenderWindow& GetWindow() { return Window; }

  void HandleSDLEvents(Player& Player);

  GameTexture LoadTexture(const char* TextureName, const char* SpriteLocation, Vector4 CurrentFrame, int FrameOffset, int Frames,
      RenderWindow Window);

  Time* Time;
  std::vector<Entity*> EntityList;

 private:
  bool isRunning;

  const char* WindowName;
  int Width;
  int Height;

  RenderWindow Window = RenderWindow(WindowName, Width, Height);

  SDL_Event currentevent;
};
