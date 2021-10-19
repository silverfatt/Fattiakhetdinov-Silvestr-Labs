#include <iostream>
#include "rhombus.h"
#include "tnary_tree.h"
int main() {
    TNaryTree t(3);
    t.Update(Rhombus(Point(0,0),Point(0,1),Point(1,1),Point(1,0)),"");
    if (t.Empty()) std::cout << "Tree is empty\n";
    else std::cout << "Tree is not empty\n";
    t.Update(Rhombus(Point(0,0),Point(0,2),Point(2,2),Point(2,0)),"c");
    t.Update(Rhombus(Point(0,0),Point(0,3),Point(3,3),Point(3,0)),"cb");
    t.Update(Rhombus(Point(0,0),Point(0,7),Point(7,7),Point(7,0)),"cbb");
    t.Update(Rhombus(Point(0,0),Point(0,5),Point(5,5),Point(5,0)),"cc");
    t.Update(Rhombus(Point(0,0),Point(0,11),Point(11,11),Point(11,0)),"cbbc");
    std::cout << t << "\n";
    t.Update(Rhombus(Point(0,0),Point(0,6),Point(6,6),Point(6,0)),"");
    t.Update(Rhombus(Point(0,0),Point(0,6),Point(6,6),Point(6,0)),"cc");
    std::cout << t << "\n";
    t.RemoveSubTree("cbb");
    std::cout << t << "\n";
    t.Update(Rhombus(Point(0,0),Point(0,8),Point(8,8),Point(8,0)),"cbb");
    std::cout << t << "\n";
    //std::cout << "Area of root is:" << t.Area("") << "\n";
    Rhombus testrhombus;
    testrhombus = t.GetItem("cbb");
    testrhombus.Print(std::cout);
    TNaryTree tcopy(t);
    t.Update(Rhombus(Point(0,0),Point(0,10),Point(10,10),Point(10,0)),"cbb");
    std::cout << "Copy:   " << tcopy << "\n";
    std::cout << "Source: " << t << "\n";
    TNaryTree tcommon;
    tcommon.Update(Rhombus(Point(0,0), Point(0,12), Point(12,12), Point(12,0)), "");
    tcommon.Update(Rhombus(Point(0,0), Point(0,13), Point(13,13), Point(13,0)), "c");
    tcommon.Update(Rhombus(Point(0,0), Point(0,14), Point(14,14), Point(14,0)), "cb");
    std::cout << tcommon << "\n";
    return 0;
}