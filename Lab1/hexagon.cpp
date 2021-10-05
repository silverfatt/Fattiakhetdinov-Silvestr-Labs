#include <cmath>

#include "hexagon.h"
Hexagon::Hexagon()
    : a(0.0, 0.0),
      b(0.0, 0.0),
      c(0.0, 0.0),
      d(0.0, 0.0),
      e(0.0, 0.0),
      f(0.0, 0.0) {
  std::cout << "Default Hexagon created" << std::endl;
}
Hexagon::Hexagon(std::istream& is) {
  is >> a >> b >> c >> d >> e >> f;
}
Hexagon::Hexagon(Point _a, Point _b, Point _c, Point _d, Point _e, Point _f) {
  a = _a;
  b = _b;
  c = _c;
  d = _d;
  e = _e;
  f = _f;
}
Hexagon::Hexagon(const Hexagon& other)
    : Hexagon(other.a, other.b, other.c, other.d, other.e, other.f) {}
void Hexagon::Print(std::ostream& os) {
  os << "Hexagon:";
  os << a << b << c << d << e << f << std::endl;
  // os << "(" << b << "." << b << ") ";
  // os << "(" << c << "." << c << ") ";
  // os << "(" << d << "." << d << ") ";
}
double Hexagon::Area() {
  double s =
      abs(a.x() * b.y() + b.x() * c.y() + c.x() * d.y() + d.x() * e.y() +
          e.x() * f.y() + f.x() * a.y() - b.x() * a.y() - c.x() * b.y() -
          d.x() * c.y() - e.x() * d.y() - f.x() * e.y() - a.x() * f.y()) /
      2;

  return s;
}
size_t Hexagon::VertexesNumber() {
  return 4;
}
Hexagon::~Hexagon() {
  std::cout << "Hexagon deleted" << std::endl;
}