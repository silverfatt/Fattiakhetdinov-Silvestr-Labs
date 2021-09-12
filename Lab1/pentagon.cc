#include "pentagon.h"
#include <cmath>
Pentagon::Pentagon(std::istream &is) {
    is >> a >> b >> c >> d >> e;
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
