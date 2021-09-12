#include <iostream>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"

using namespace std;

int main()
{
    std::cout << "Enter Rhombus coordinates" << endl;
    Rhombus a(std::cin);
    std::cout << a.VertexesNumber() << std::endl;
    a.Print(std::cout);
    std::cout << "Area is: " << a.Area() << std::endl;

    std::cout << "Enter Pentagon coordinates" << endl;
    Pentagon b(std::cin);
    std::cout << b.VertexesNumber() << std::endl;
    b.Print(std::cout);
    std::cout << "Area is: " << b.Area() << std::endl;

    std::cout << "Enter Hexagon coordinates" << endl;
    Hexagon c(std::cin);
    std::cout << c.VertexesNumber() << std::endl;
    c.Print(std::cout);
    std::cout << "Area is: " << c.Area() << std::endl;
}