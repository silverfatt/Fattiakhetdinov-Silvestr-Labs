#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure
{
public:
    Rhombus();
    Rhombus(Point a, Point b, Point c, Point d);
    Rhombus(const Rhombus &other);
    Rhombus(std::istream &is);

    double Area();
    size_t VertexesNumber();
    void Print(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, const Rhombus &figure);

    ~Rhombus();

private:
    Point a, b, c, d;
};

#endif // RHOMBUS_H
