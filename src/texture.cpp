#include "../include/texture.h"

#include <cstdint>

void GameTexture::PlayAnimation() {
  static uint32_t Frame = 0;
  if (Frame < Frames) {
    Frame += 1;
  }

  if (Frame == Frames) {
    Frame = 0;
    CurrentFrame.x = FrameOffset * 0.5;
    OnAnimationFinish.invoke();
    return;
  }

  CurrentFrame.x += FrameOffset;
}
