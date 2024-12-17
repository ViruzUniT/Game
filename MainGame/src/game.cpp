#include "../include/world.h"

void Game::StartGame() {
  Timer startupTimer = Timer();
  isRunning = true;
  Timing.SetWindow(GetWindow());
  startupTimer.Stop();
}

void Game::RunGame() {
  World::SetCurrentGame(this);
  std::cout << "Set CurrentGame to: " << World::GetCurrentGame() << std::endl;

  World::CreatePlayer("Main Player", Vector2(100, 100));
  std::cout << "Created Player\n";

  ObjectsRunStart();
  std::cout << "Called ObjectsRunStart()\n";

  while (isRunning == true) {
    Timing.StartMeasure();
    while (Timing.accumulator >= Timing.timeStep) {
      ObjectsRunTick();
      Timing.accumulator -= Timing.timeStep;
    }
    Window.Clear();
    Window.Render();
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
