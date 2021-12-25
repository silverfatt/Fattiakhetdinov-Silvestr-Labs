#include <iostream>
#include "rhombus.h"
#include "tnary_tree.h"
int main(){
    TNaryTree<Rhombus> t(3);
    //std::cout << "CrashTest";
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0))), "");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0))), "c");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 3), Point(3, 3), Point(3, 0))), "cb");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 7), Point(7, 7), Point(7, 0))), "cbb");
    t.Update(std::shared_ptr<Rhombus>(new Rhombus(Point(0, 0), Point(0, 5), Point(5, 5), Point(5, 0))), "cc");
    //std::cout << "CrashTest";
    TIterator<TnaryTreeItem<Rhombus>, Rhombus> iter(t.getroot());
    //std::cout << "CrashTest";
    std::cout << *iter << std::endl;
    iter.GoToSon();
    std::cout << *iter << std::endl;
    iter.GoToBro();
    std::cout << *iter << std::endl;
    TIterator<TnaryTreeItem<Rhombus>, Rhombus> iter1(t.getroot());
    TIterator<TnaryTreeItem<Rhombus>, Rhombus> iter2(t.getroot());
    if (iter == iter1) std::cout << "Iter = Iter1" << std::endl;
    if (iter !=iter1) std::cout << "Iter != Iter1" << std::endl;
    if (iter1 == iter2) std::cout << "Iter1 = Iter2" << std::endl;
    if (iter1 !=iter2) std::cout << "Iter1 != Iter2" << std::endl;
}