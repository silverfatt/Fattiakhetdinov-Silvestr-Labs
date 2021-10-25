#include <iostream>
#include "rhombus.h"
#include "tnary_tree.h"

int main()
{
    TNaryTree<Rhombus> t(3);
    // t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0))), "");
    Point x1(2, 2);
    Point x2(2, 0);
    Point x3(0, 0);
    Point x4(0, 2);
    Point y1(1, 1);
    Point y2(1, 0);
    Point y3(0, 0);
    Point y4(0, 1);
    std::shared_ptr<Rhombus> s1(new Rhombus(x1, x2, x3, x4));
    std::shared_ptr<Rhombus> s2(new Rhombus(y1, y2, y3, y4));
    
    t.Update(s1, "");
    std::cout << t << std::endl;

    if (t.Empty()) {
        std::cout << "Tree is empty\n";
    } else {
        std::cout << "Tree is not empty\n";
    }

    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0))), "c");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 3), Point(3, 3), Point(3, 0))), "cb");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 7), Point(7, 7), Point(7, 0))), "cbb");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 5), Point(5, 5), Point(5, 0))), "cc");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 11), Point(11, 11), Point(11, 0))), "cbbc");
    std::cout << t << std::endl;
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 6), Point(6, 6), Point(6, 0))), "");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 6), Point(6, 6), Point(6, 0))), "cc");
    std::cout << t << std::endl;
    t.RemoveSubTree("cbb");
    std::cout << t << std::endl;
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 8), Point(8, 8), Point(8, 0))), "cbb");
    std::cout << t << std::endl;
    
    TNaryTree<Rhombus> tcommon;
    tcommon.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 12), Point(12, 12), Point(12, 0))), "");
    tcommon.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 13), Point(13, 13), Point(13, 0))), "c");
    tcommon.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 14), Point(14, 14), Point(14, 0))), "cb");
    std::cout << "test" << std::endl;
    std::cout << tcommon << std::endl;
    return 0;
}