#pragma once
#include <cstdint>

#include "SDL.h"
#include "eventhandler.h"

struct GameTexture {
 public:
  GameTexture(const char* textureName, SDL_Texture* texture, const SDL_Rect& currentFrame, const int& frameOffset, const int& frames)
      : TextureName(textureName), Texture(texture), CurrentFrame(currentFrame), FrameOffset(frameOffset), Frames(frames) {}

  Event<uint32_t> OnAnimationFinish;

  const char* TextureName;
  const SDL_Texture* Texture;
  const SDL_Rect CurrentFrame;
  const int FrameOffset;
  const int Frames;
};
