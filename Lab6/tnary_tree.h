// Если какой-то вершины в tree_path не существует,
//  то функция должна бросить исключение std::invalid_argument
// Если вершину нельзя добавить из за переполнения,
//  то функция должна бросить исключение std::out_of_range
#ifndef TLIST_H
#define TLIST_H

#include "tnary_tree_item.h"
#include "titerator.h"

template <class T>
class TNaryTree
{
public:
    TNaryTree();
    TNaryTree(int n);

    void Update(std::shared_ptr<T> r, std::string tree_path);
    void RemoveSubTree(std::string tree_path);
    const std::shared_ptr<T> &GetItem(const std::string tree_path);
    bool Empty();
    std::shared_ptr<TnaryTreeItem<T>> getroot();
    template <class A>
    friend std::ostream &operator<<(std::ostream &os, const TNaryTree<A> &tree);
    
    virtual ~TNaryTree();

private:
    void Clearh(std::shared_ptr<TnaryTreeItem<T>> it);                         // helper
    void Printh(std::shared_ptr<TnaryTreeItem<T>> it, std::ostream &os) const; // helper
    int N;
    std::shared_ptr<TnaryTreeItem<T>> root;
};

#endif // TLIST_H