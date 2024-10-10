#pragma once
#include <functional>
#include <iostream>
#include <vector>

template <typename... Args>
struct Event {
 public:
  Event() = default;
  Event(const Event &) = delete;
  const Event *operator=(const Event &) = delete;

  using Callback = std::function<void(Args...)>;

  void add(const Callback &callback) { callbacks.push_back(callback); }

  void invoke(Args... args) {
    for (auto &callback : callbacks) {
      callback(args...);
    }
  }

 private:
  std::vector<Callback> callbacks;
};
