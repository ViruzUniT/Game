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
  std::cout << "Created idle texture\n";
  Player* player = World::CreatePlayer(Vector2(100, 100),
      LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 5, Window), *this);
  std::cout << "Created Player\n";
  player->AddTexture(LoadTexture("Walk", "./sprites/Fighter/Walk.png", Vector4(46, 45, 24, 83), 104, 7, Window));
  std::cout << "Added Walk Texture\n";

  while (isRunning == true) {
    Timing.StartMeasure();
    while (Timing.accumulator >= Timing.timeStep) {
      HandleSDLEvents(*player);
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
}

void Game::HandleSDLEvents(Player& Player) {
  while (SDL_PollEvent(&currentevent)) {
    switch (currentevent.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            Player.Dir.up = true;
            break;
          case SDLK_a:
            Player.Dir.left = true;
            break;
          case SDLK_s:
            Player.Dir.down = true;
            break;
          case SDLK_d:
            Player.Dir.right = true;
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch (currentevent.key.keysym.sym) {
          case SDLK_w:
            Player.Dir.up = false;
            break;
          case SDLK_a:
            Player.Dir.left = false;
            break;
          case SDLK_s:
            Player.Dir.down = false;
            break;
          case SDLK_d:
            Player.Dir.right = false;
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
  Player.Move(Timing, Player);
  Player.PlayAnimation();
}

GameTexture* Game::LoadTexture(const char* TextureName, const char* SpriteLocation, const Vector4& CurrentFrame, const int& FrameOffset,
    const int& Frames, RenderWindow& Window) {
  SDL_Texture* texture = Window.LoadTexture(SpriteLocation);

  SDL_Rect currentFrame;
  currentFrame.x = CurrentFrame.x;
  currentFrame.y = CurrentFrame.y;
  currentFrame.h = CurrentFrame.h;
  currentFrame.w = CurrentFrame.w;
  return new GameTexture(TextureName, texture, currentFrame, FrameOffset, Frames);
}
