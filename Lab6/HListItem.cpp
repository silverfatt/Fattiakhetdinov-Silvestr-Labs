#include <iostream>
#include "HListItem.h"

template <class T>
HListItem<T>::HListItem(const std::shared_ptr<Rhombus> &rhombus)
{
    this->rhombus = rhombus;
    this->next = nullptr;
}
template <class A>
std::ostream &operator<<(std::ostream &os, HListItem<A> &obj)
{
    os << "[" << obj.rhombus << "]" << std::endl;
    return os;
}
template <class T>
HListItem<T>::~HListItem()
{
}