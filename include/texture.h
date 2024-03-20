#pragma once
#include <cstdint>
#include <cstdio>

#include "SDL.h"
#include "eventhandler.h"

class GameTexture {
 public:
  GameTexture(const char* textureName, SDL_Texture* texture, const SDL_Rect& currentFrame, const int& frameOffset, const int& frames)
      : TextureName(textureName),
        Texture(texture),
        CurrentFrame(currentFrame),
        FrameOffset(frameOffset),
        Frames(frames),
        FirstCurrentFramePos(currentFrame.x) {
    printf("%s, %d\n", TextureName, Frames);
  }
  GameTexture(const GameTexture& other)
      : TextureName(other.TextureName),
        Texture(other.Texture),
        CurrentFrame(other.CurrentFrame),
        FrameOffset(other.FrameOffset),
        Frames(other.Frames),
        FirstCurrentFramePos(other.FirstCurrentFramePos) {}

  void operator=(const GameTexture& other) {
    TextureName = other.TextureName;
    Texture = other.Texture;
    CurrentFrame = other.CurrentFrame;
    FrameOffset = other.FrameOffset;
    Frames = other.Frames;
    FirstCurrentFramePos = other.FirstCurrentFramePos;
  }

  Event<> OnAnimationFinish;
  // Event<> CustomAnimationEvent;

  const char* TextureName;
  SDL_Texture* Texture;
  SDL_Rect CurrentFrame;
  int FrameOffset;
  int Frames;
  int FirstCurrentFramePos;

 private:
  int FpsLock;
};
