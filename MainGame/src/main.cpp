#include <Windows.h>

#include "../include/game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
  Game Game("Game v0.1.5", 825, 480);
  Game.StartGame();
  Game.RunGame();
  return 0;
}
