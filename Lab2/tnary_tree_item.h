#ifndef TNARY_TREE_ITEM_H
#define TNARY_TREE_ITEM_H
#include "rhombus.h"

class TnaryTreeItem
{
public:
public:
  TnaryTreeItem();
  TnaryTreeItem(Rhombus &rhombus);
  TnaryTreeItem *son;
  TnaryTreeItem *brother;
  virtual ~TnaryTreeItem();
  Rhombus rhombus;
};

#endif // TNARY_TREE_ITEM_H
