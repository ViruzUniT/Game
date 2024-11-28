#pragma once
struct Vector2 {
 public:
  Vector2() : x(0), y(0) {}
  Vector2(double x, double y) : x(x), y(y) {}

  inline void operator=(Vector2& other) {
    x = other.x;
    y = other.y;
  }

  double x, y;
};

struct Vector3 {
  Vector3() : x(0), y(0), z(0) {}
  Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

  double x, y, z;
};

struct Vector4 {
  Vector4() : x(0), y(0), w(0), h(0) {}
  Vector4(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {}

  double x, y, w, h;
};

inline float square(float x) { return x * x; }
