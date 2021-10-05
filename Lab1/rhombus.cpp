#include <cmath>

#include "rhombus.h"
Rhombus::Rhombus() : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0) {
  std::cout << "Default Rhombus created" << std::endl;
}
Rhombus::Rhombus(std::istream& is) {
  is >> a >> b >> c >> d;
}
Rhombus::Rhombus(Point _a, Point _b, Point _c, Point _d) {
  if (sqrt((_b.x() - _a.x()) * (_b.x() - _a.x()) +
           (_b.y() - _a.y()) * (_b.y() - _a.y())) ==
          sqrt((_c.x() - _b.x()) * (_c.x() - _b.x()) +
               (_c.y() - _b.y()) * (_c.y() - _b.y())) &&
      sqrt((_c.x() - _b.x()) * (_c.x() - _b.x()) +
           (_c.y() - _b.y()) * (_c.y() - _b.y())) ==
          sqrt((_d.x() - _c.x()) * (_d.x() - _c.x()) +
               (_d.y() - _c.y()) * (_d.y() - _c.y())) &&
      sqrt((_d.x() - _c.x()) * (_d.x() - _c.x()) +
           (_d.y() - _c.y()) * (_d.y() - _c.y())) ==
          sqrt((_a.x() - _d.x()) * (_a.x() - _d.x()) +
               (_a.y() - _d.y()) * (_a.y() - _d.y()))) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
  } else {
    std::cout << "Invalid arguements";
  }
}
Rhombus::Rhombus(const Rhombus& other)
    : Rhombus(other.a, other.b, other.c, other.d) {}
void Rhombus::Print(std::ostream& os) {
  os << "Rhombus:";
  os << a << b << c << d << std::endl;
  // os << "(" << b << "." << b << ") ";
  // os << "(" << c << "." << c << ") ";
  // os << "(" << d << "." << d << ") ";
}
double Rhombus::Area() {
  double s =
      abs(a.x() * b.y() + b.x() * c.y() + c.x() * d.y() + d.x() * a.y() -
          b.x() * a.y() - c.x() * b.y() - d.x() * c.y() - a.x() * d.y()) /
      2;

  return s;
}
size_t Rhombus::VertexesNumber() {
  return 4;
}
Rhombus::~Rhombus() {
  std::cout << "Rhombus deleted" << std::endl;
}
