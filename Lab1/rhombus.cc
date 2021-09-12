#include "rhombus.h"
#include <cmath>
Rhombus::Rhombus(std::istream &is) {
    is >> a >> b >> c >> d;
}
void Rhombus::Print(std::ostream &os){
    os << "Rhombus:";
    os << a << b << c << d << std::endl;
    // os << "(" << b << "." << b << ") ";
    // os << "(" << c << "." << c << ") ";
    // os << "(" << d << "." << d << ") ";
}
double Rhombus::Area(){
    double s = abs(a.x() * b.y() + b.x() *c.y() + c.x()*d.y() + d.x()*a.y() - b.x()*a.y() - c.x()*b.y() - d.x()*c.y() - a.x()*d.y())/2;

    return s;
} 
size_t Rhombus::VertexesNumber(){
    return 4;
}
Rhombus::~Rhombus() {
    std::cout << "Rhombus deleted" << std::endl;
}
