#include "../include/game.h"

#include "../include/player.h"

void Game::RunGame() {
  GameTexture playerIdleTexture = LoadTexture("Idle", "./sprites/Fighter/Idle.png", Vector4(46, 47, 30, 81), 98, 5, Window);
  Player Player(Vector2(100, 100), playerIdleTexture, *this);
  Player.AddTexture(LoadTexture("Walk", "./sprites/Fighter/Walk.png", Vector4(46, 45, 24, 83), 104, 7, Window));

  while (isRunning == true) {
    Time->StartMeasure();
    while (Time->accumulator >= Time->timeStep) {
      HandleSDLEvents(Player);
      Time->accumulator -= Time->timeStep;
    }

    Window.Clear();
    Window.Render(Player, this);
    Window.Display();

    Time->EndMeasure();
    Time->FrameLimitPause();
    Time->ShowFPS();
  }
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
  Player.Move(*this->Time, Player);
  Player.PlayAnimation();
}

GameTexture Game::LoadTexture(const char* TextureName, const char* SpriteLocation, Vector4 CurrentFrame, int FrameOffset, int Frames,
    RenderWindow Window) {
  SDL_Texture* texture = Window.LoadTexture(SpriteLocation);

  SDL_Rect currentFrame;
  currentFrame.x = CurrentFrame.x;
  currentFrame.y = CurrentFrame.y;
  currentFrame.h = CurrentFrame.h;
  currentFrame.w = CurrentFrame.w;
  return GameTexture(TextureName, texture, currentFrame, FrameOffset, Frames);
}
