#ifndef TNARY_TREE_ITEM_H
#define TNARY_TREE_ITEM_H
#include "rhombus.h"
#include <memory>

class TnaryTreeItem {
public:
public:
    TnaryTreeItem();
    TnaryTreeItem(Rhombus& rhombus);
    std::shared_ptr<TnaryTreeItem> son;
    std::shared_ptr<TnaryTreeItem> brother;
    Rhombus rhombus;
};
 
#endif // TNARY_TREE_ITEM_H
