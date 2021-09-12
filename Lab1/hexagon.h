#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <iostream>

class Hexagon : public Figure {
    public:
    Hexagon();
    Hexagon(std::istream& is);
    virtual ~Hexagon();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &os);
    private:
    Point a,b,c,d,e,f;
};

#endif // HEXAGON_H