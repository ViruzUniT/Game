#include "../include/texture.h"

#include <cstdint>

#include "../include/time.h"

#define FPS_TIME 0.01

extern Time Time;

void GameTexture::PlayAnimation() {
  static uint16_t Frame = 0;

  // Capping Animation FPS to 30
  static float time = 0.0f;
  time += Time.deltaTime;
  if (time >= FPS_TIME) {
    time = 0.0f;
    if (Frame < Frames) {
      Frame += 1;
    }

    if (Frame == Frames) {
      Frame = 0;
      CurrentFrame.x = FirstCurrentFramePos;
      OnAnimationFinish.invoke();
      return;
    }

    CurrentFrame.x += FrameOffset + CurrentFrame.w;
  }
}
