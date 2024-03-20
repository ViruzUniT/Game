#pragma once
#include <chrono>
#include <iostream>
struct Timer {
 public:
  Timer() { m_StartTimePoint = std::chrono::high_resolution_clock::now(); }
  ~Timer() { Stop(); }
  void Stop() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
    auto duration = end - start;
    double ms = duration * 0.001;
    double s = duration / 1000000.0;
    std::cout << s << " s (" << ms << " ms, " << duration << " us)\n";
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};
