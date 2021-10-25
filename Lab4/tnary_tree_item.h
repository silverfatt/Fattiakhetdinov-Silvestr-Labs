#ifndef TNARY_TREE_ITEM_H
#define TNARY_TREE_ITEM_H

#include <memory>
#include <iostream>

template <class T>
class TnaryTreeItem
{
public:
    // TnaryTreeItem();
    TnaryTreeItem(const std::shared_ptr<T> &r);
    TnaryTreeItem(const TnaryTreeItem &other);
    
    template<class A>
    friend std::ostream &operator<<(std::ostream &os, const TnaryTreeItem<A> &obj);
    
    virtual ~TnaryTreeItem();

    std::shared_ptr<TnaryTreeItem<T>> son;
    std::shared_ptr<TnaryTreeItem<T>> brother;
    std::shared_ptr<T> rhombus;
};

#endif // TNARY_TREE_ITEM_H
