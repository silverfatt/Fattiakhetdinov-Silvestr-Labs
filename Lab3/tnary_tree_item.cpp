#include "tnary_tree_item.h"
#include "rhombus.h"
#include <iostream>

TnaryTreeItem::TnaryTreeItem(Rhombus& r) {
  this->rhombus = r;
  this->son = nullptr;
  this->brother = nullptr;
  std::cout << "Ntree item: created" << std::endl;
}