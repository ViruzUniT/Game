#include "../include/texture.h"

#include <cstdint>

#include "../include/time.h"

extern Time Time;

void GameTexture::PlayAnimation() {
  static uint16_t Frame = 0;

  // Capping Animation FPS to 30
  static float time = 0.0f;
  time += Time.deltaTime;
  if (time >= 0.5) {
    time = 0.0f;
    if (Frame < Frames) {
      Frame += 1;
    }

    if (Frame == Frames) {
      Frame = 0;
      CurrentFrame.x = FrameOffset * 0.5;
      // std::cout << CurrentFrame.x << "\n";
      OnAnimationFinish.invoke();
      return;
    }

    CurrentFrame.x += (FrameOffset + CurrentFrame.h);
    // std::cout << CurrentFrame.x << "\n";
  }
}
