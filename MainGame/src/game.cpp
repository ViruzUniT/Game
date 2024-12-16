#include "../include/game.h"

#include "../include/player.h"
#include "../include/world.h"

void Game::StartGame() {
  Timer startupTimer = Timer();
  isRunning = true;
  Timing.SetWindow(GetWindow());
  startupTimer.Stop();
}

void Game::RunGame() {
  Player* player = World::CreatePlayer("Main Player", Vector2(100, 100));
  std::cout << "Created Player\n";

  ObjectsRunStart();

  while (isRunning == true) {
    Timing.StartMeasure();
    while (Timing.accumulator >= Timing.timeStep) {
      ObjectsRunTick();
      Timing.accumulator -= Timing.timeStep;
    }

    Window.Clear();
    Window.Render(this);
    Window.Display();

    Timing.EndMeasure();
    Timing.FrameLimitPause();
    Timing.ShowFPS();
  }
  World::DestroyAllEntities();
  Window.CleanUp();
  Window.DestroyWindowAndRenderer();
  SDL_Quit();
  std::cout << "Game Quitted\n";
}

GameTexture* Game::LoadTexture(const char* TextureName, const char* SpriteLocation,
    const Vector4& CurrentFrame, const int& FrameOffset, const int& Frames) {
  SDL_Texture* texture = Window.LoadTexture(SpriteLocation);
  if (texture == nullptr) {
    return nullptr;
  }

  SDL_Rect currentFrame;
  currentFrame.x = CurrentFrame.x;
  currentFrame.y = CurrentFrame.y;
  currentFrame.h = CurrentFrame.h;
  currentFrame.w = CurrentFrame.w;
  return new GameTexture(TextureName, texture, currentFrame, FrameOffset, Frames);
}

void Game::ObjectsRunStart() {
  for (Object*& object : World::GetObjects()) {
    object->Start();
  }
}

void Game::ObjectsRunTick() {
  for (Object*& object : World::GetObjects()) {
    if (object->GetRunTick())
      object->Tick();
  }
}
