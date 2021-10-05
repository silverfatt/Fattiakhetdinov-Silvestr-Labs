#include "pentagon.h"
#include <cmath>
Pentagon::Pentagon()
    : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0), e(0.0, 0.0) {
  std::cout << "Default Pentagon created" << std::endl;
}
Pentagon::Pentagon(std::istream &is) {
    is >> a >> b >> c >> d >> e;
}
Pentagon::Pentagon(Point _a, Point _b, Point _c, Point _d, Point _e) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
    e = _e;
}
Pentagon::Pentagon(const Pentagon& other) : Pentagon(other.a, other.b, other.c, other.d, other.e) {
}
void Pentagon::Print(std::ostream &os){
    os << "Pentagon:";
    os << a << b << c << d << e << std::endl;
    // os << "(" << b << "." << b << ") ";
    // os << "(" << c << "." << c << ") ";
    // os << "(" << d << "." << d << ") ";
}
double Pentagon::Area(){
    double s = abs(a.x() * b.y() + b.x() *c.y() + c.x()*d.y() + d.x()*e.y() + e.x()*a.y() - b.x()*a.y() - c.x()*b.y() - d.x()*c.y() - e.x()*d.y() - a.x()*e.y() )/2;

    return s;
} 
size_t Pentagon::VertexesNumber(){
    return 4;
}
Pentagon::~Pentagon() {
    std::cout << "Pentagon deleted" << std::endl;
}
