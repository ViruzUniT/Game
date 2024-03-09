#include "../include/texture.h"

#include <cstdint>
#include <cstdio>

#include "../include/time.h"

#define FPS 31.0f

extern Time Time;

void GameTexture::PlayAnimation() {
  static uint16_t Frame = 0;

  // Capping Animation FPS to 30
  static float time = 0.0f;
  time += Time.deltaTime;
  float fps = 1 / time;
  printf("FPS: %f\n", fps);
  if (fps <= FPS) {
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
