#pragma once

#include "SDL.h"
#include "math.h"
#include "renderer.h"
#include "texture.h"
#include "time.h"
#include "timer.h"

class Player;

struct Game {
 public:
  Game(const char* WindowName, int Width, int Height)
      : WindowName(WindowName), Width(Width), Height(Height), Window(RenderWindow(WindowName, Width, Height)) {}
  ~Game() { delete WindowName; }

  void StartGame();
  void RunGame();

  inline bool IsGameRunning() { return isRunning; }
  RenderWindow& GetWindow() { return Window; }

  void HandleSDLEvents(Player& Player);

  GameTexture LoadTexture(const char* TextureName, const char* SpriteLocation, Vector4 CurrentFrame, int FrameOffset, int Frames,
      RenderWindow Window);
  inline void AddEntityToList(Entity* Entity) {
    std::cout << "Pushed back Entity: " << Entity << std::endl;
    EntityList.push_back(Entity);
  }
  inline std::vector<Entity*> GetEntityList() { return EntityList; }

  Time Timing;

 private:
  bool isRunning;

  const char* WindowName;
  int Width;
  int Height;

  RenderWindow Window;

  SDL_Event currentevent;

  std::vector<Entity*> EntityList;
};
