#pragma once
#include <functional>
#include <iostream>
#include <vector>

template <typename... Args>
class Event {
 public:
  Event() = default;
  using Callback = std::function<void(Args...)>;

  void add(const Callback &callback) { callbacks.push_back(callback); }

  void invoke(Args... args) {
    for (auto &callback : callbacks) {
      callback(args...);
    }
  }

  Event(const Event &) = delete;
  const Event *operator=(const Event &) = delete;

 private:
  std::vector<Callback> callbacks;
};
