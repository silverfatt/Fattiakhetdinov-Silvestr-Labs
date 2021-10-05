#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <iostream>

class Pentagon : public Figure {
    public:
    Pentagon();
    Pentagon(std::istream& is);
    Pentagon(Point a, Point b, Point c, Point d, Point e);
    Pentagon(const Pentagon& other);
    virtual ~Pentagon();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &os);
    private:
    Point a,b,c,d,e;
};

#endif // PENTAGON_H