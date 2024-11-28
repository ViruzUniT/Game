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
  Player* player = World::CreatePlayer("Main Player", Vector2(100, 100),
      LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 5,
          Window),
      *this);
  std::cout << "Created Player\n";
  player->AddTexture(LoadTexture("Walk", "./sprites/Fighter/Walk.png",
      Vector4(46, 45, 24, 83), 104, 7, Window));
  player->AddTexture(LoadTexture("Punch", "./sprites/Fighter/Attack_1.png",
      Vector4(38, 47, 53, 81), 92 - 17, 4, Window));
  player->OnAnimationFinish.add(
      std::bind(&Player::StopPunch, player, std::placeholders::_1));

  while (isRunning == true) {
    Timing.StartMeasure();
    while (Timing.accumulator >= Timing.timeStep) {
      player->HandleSDLEvents(this);
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
    const Vector4& CurrentFrame, const int& FrameOffset, const int& Frames,
    RenderWindow& Window) {
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
