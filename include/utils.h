#pragma once
#include "SDL.h"

class GameTexture {
 public:
  GameTexture(SDL_Texture* texture, const SDL_Rect& currentFrame, const int& FrameOffset)
      : texture(texture), CurrentFrame(currentFrame), frameOffset(FrameOffset) {}
  SDL_Texture* texture;
  SDL_Rect CurrentFrame;
  int frameOffset;
};
