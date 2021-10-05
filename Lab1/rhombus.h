#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <iostream>

class Rhombus : public Figure {
    public:
    Rhombus();
    Rhombus(std::istream& is);
    Rhombus(Point a, Point b, Point c, Point d);
    Rhombus(const Rhombus& other);
    virtual ~Rhombus();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &os);
    private:
    Point a,b,c,d;
};

#endif // RHOMBUS_H
