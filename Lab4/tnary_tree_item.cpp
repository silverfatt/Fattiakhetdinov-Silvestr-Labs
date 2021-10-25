#include "tnary_tree_item.h"

template <class T>
TnaryTreeItem<T>::TnaryTreeItem(const std::shared_ptr<T> &r)
{
    this->rhombus = r;
    this->son = nullptr;
    this->brother = nullptr;
    std::cout << "Ntree item: created" << std::endl;
}

template <class T>
TnaryTreeItem<T>::TnaryTreeItem(const TnaryTreeItem &other)
{
    this->rhombus = other.rhombus;
    this->son = other.son;
    this->brother = other.brother;
    std::cout << "Ntree item: copied" << std::endl;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const TnaryTreeItem<T> &obj)
{
    os << "Item: " << *obj.rhombus << std::endl;
    return os;
}

template <class T>
TnaryTreeItem<T>::~TnaryTreeItem() {}

#include "rhombus.h"
template class TnaryTreeItem<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TnaryTreeItem<Rhombus>& obj);