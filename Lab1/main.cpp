#include <iostream>

#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"

using namespace std;

int main() {
  std::cout << "Enter Rhombus coordinates" << std::endl;
  Rhombus a(std::cin);
  std::cout << a.VertexesNumber() << std::endl;
  a.Print(std::cout);
  std::cout << "Area is: " << a.Area() << std::endl;
  Rhombus a1;
  std::cout << "Default Rhombus coordinates: " << std::endl;
  a1.Print(std::cout);
  std::cout << "Default Rhombus area is: " << a1.Area() << std::endl;
  Rhombus a2(Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0));
  std::cout << "Rhombus 2 coordinates are: " << std::endl;
  a2.Print(std::cout);
  std::cout << "Rhombus 2 area is:" << a2.Area() << std::endl;
  Rhombus a3(a2);
  std::cout << "Rhombus 3 coordinates are: " << std::endl;
  a3.Print(std::cout);
  std::cout << "Rhombus 3 area is:" << a3.Area() << std::endl;

  std::cout << "Enter Pentagon coordinates" << std::endl;
  Pentagon b(std::cin);
  std::cout << b.VertexesNumber() << std::endl;
  b.Print(std::cout);
  std::cout << "Area is: " << b.Area() << std::endl;
  Pentagon b1;
  std::cout << "Default Pentagon coordinates: " << std::endl;
  b1.Print(std::cout);
  std::cout << "Default Pentagon area is: " << b1.Area() << std::endl;
  Pentagon b2(Point(0, 0), Point(0, 1), Point(1, 1), Point(1.5, 0.5),
              Point(1, 0));
  std::cout << "Pentagon 2 coordinates are: " << std::endl;
  b2.Print(std::cout);
  std::cout << "Pentagon 2 area is:" << b2.Area() << std::endl;
  Pentagon b3(b2);
  std::cout << "Pentagon 3 coordinates are: " << std::endl;
  b3.Print(std::cout);
  std::cout << "Pentagon 3 area is:" << b3.Area() << std::endl;

  std::cout << "Enter Hexagon coordinates" << std::endl;
  Hexagon c(std::cin);
  std::cout << c.VertexesNumber() << std::endl;
  c.Print(std::cout);
  std::cout << "Area is: " << c.Area() << std::endl;
  Hexagon c1;
  std::cout << "Default Hexagon coordinates: " << std::endl;
  c1.Print(std::cout);
  std::cout << "Default Hexagon area is: " << c1.Area() << std::endl;
  Hexagon c2(Point(0, 0), Point(0, 1), Point(1, 1), Point(1.5, 0.5),
             Point(1, 0.2), Point(1, 0));
  std::cout << "Hexagon 2 coordinates are: " << std::endl;
  c2.Print(std::cout);
  std::cout << "Hexagon 2 area is:" << c2.Area() << std::endl;
  Hexagon c3(c2);
  std::cout << "Hexagon 3 coordinates are: " << std::endl;
  c3.Print(std::cout);
  std::cout << "Hexagon 3 area is:" << c3.Area() << std::endl;
}