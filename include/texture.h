#pragma once
#include "SDL.h"

class GameTexture {
 public:
  GameTexture(const char* textureName, SDL_Texture* texture, const SDL_Rect& currentFrame, const int& frameOffset)
      : TextureName(textureName), Texture(texture), CurrentFrame(currentFrame), FrameOffset(frameOffset) {}
  const char* TextureName;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
  int FrameOffset;
};
