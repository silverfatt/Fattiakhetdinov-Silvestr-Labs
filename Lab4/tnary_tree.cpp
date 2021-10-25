#include "tnary_tree.h"

template <class T>
TNaryTree<T>::TNaryTree()
{
    root = nullptr;
    N = 3;
}

template <class T>
TNaryTree<T>::TNaryTree(int A)
{
    root = nullptr;
    N = A;
}

template <class T>
const std::shared_ptr<T> &TNaryTree<T>::GetItem(const std::string tree_path)
{
    if (tree_path == "") {
        if (root == nullptr) {
            throw std::invalid_argument("The node doesn't exist");
        } else {
            return root->rhombus;
        }
    } else {
        std::shared_ptr<TnaryTreeItem<T>> it = root;
        int counter = 1;
        for (size_t i = 0; i < tree_path.size() - 1; ++i) {
            if (tree_path[i] == 'b') {
                ++counter;
                it = it->brother;
                if (it == nullptr) {
                    throw std::invalid_argument("The node doesn't exist");
                }
            }
            if (tree_path[i] == 'c') {
                counter = 1;
                it = it->son;
                if (it == nullptr) {
                    throw std::invalid_argument("The node doesn't exist");
                }
            }
        }
        if (tree_path[tree_path.size() - 1] == 'c') {
            if (it->son == nullptr) {
                throw std::invalid_argument("The node doesn't exist");
            } else {
                return it->son->rhombus;
            }
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            ++counter;
            if (counter > N) {
                throw std::out_of_range("The node doesn't exist");
            }
            if (it->brother == nullptr) {
                throw std::invalid_argument("The node doesn't exist");
            } else {
                return it->brother->rhombus;
            }
        }
    }
    return NULL;
}

template <class T>
void TNaryTree<T>::Update(std::shared_ptr<T> r, std::string tree_path)
{
    if (tree_path == "") {
        if (root == nullptr) {
            std::shared_ptr<TnaryTreeItem<T>> a(new TnaryTreeItem<T>(r));
            root = a;
        } else {
            root->rhombus = r;
        }
    } else {
        std::shared_ptr<TnaryTreeItem<T>> it = root;
        int counter = 1;
        for (size_t i = 0; i < tree_path.size() - 1; ++i) {
            if (tree_path[i] == 'b') {
                ++counter;
                it = it->brother;
                if (it == nullptr) {
                    throw std::invalid_argument("The node doesn't exist");
                }
            }
            if (tree_path[i] == 'c') {
                counter = 1;
                it = it->son;
                if (it == nullptr) {
                    throw std::invalid_argument("The node doesn't exist");
                }
            }
        }
        if (tree_path[tree_path.size() - 1] == 'c') {
            if (it->son == nullptr) {
                std::shared_ptr<TnaryTreeItem<T>> it1(new TnaryTreeItem<T>(r));
                it->son = it1;
            } else {
                it->son->rhombus = r;
            }
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            ++counter;
            if (counter > N) {
                throw std::out_of_range("Node cannot be added due to overflow");
            }
            if (it->brother == nullptr) {
                std::shared_ptr<TnaryTreeItem<T>> it1(new TnaryTreeItem<T>(r));
                it->brother = it1;
            } else {
                it->brother->rhombus = r;
            }
        }
    }
}

template <class T>
bool TNaryTree<T>::Empty()
{
    return root == nullptr;
}

template <class T>
void TNaryTree<T>::RemoveSubTree(std::string tree_path)
{
    std::shared_ptr<TnaryTreeItem<T>> it;
    if (tree_path == "") {
        Clearh(root);
    } else {
        it = root;
        for (size_t i = 0; i < tree_path.size() - 1; ++i) {
            if (tree_path[i] == 'b') {
                it = it->brother;
            }
            if (tree_path[i] == 'c') {
                it = it->son;
            }
        }
        if (tree_path[tree_path.size() - 1] == 'c') {
            std::shared_ptr<TnaryTreeItem<T>> it_d = it->son;
            it->son = nullptr;
            Clearh(it_d);
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            std::shared_ptr<TnaryTreeItem<T>> it_d = it->brother;
            it->brother = nullptr;
            Clearh(it_d);
        }
    }
}

template <class T>
void TNaryTree<T>::Clearh(std::shared_ptr<TnaryTreeItem<T>> it)
{
    if (it->brother != nullptr) {
        std::shared_ptr<TnaryTreeItem<T>> it_d1 = it->brother;
        it->brother = nullptr;
        Clearh(it_d1);
    }
    if (it->son != nullptr) {
        std::shared_ptr<TnaryTreeItem<T>> it_d2 = it->son;
        it->son = nullptr;
        Clearh(it_d2);
    }
    // delete it;
    return;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const TNaryTree<T> &tree)
{
    os << "TREE: ";
    std::shared_ptr<TnaryTreeItem<T>> it = tree.root;
    tree.Printh(it, os);
    return os;
}

template <class T>
void TNaryTree<T>::Printh(std::shared_ptr<TnaryTreeItem<T>> it, std::ostream &os) const
{
    T rhomb = *(it->rhombus);
    os << rhomb.Area();
    if (it->son != nullptr) {
        os << ": [";
        Printh(it->son, os);
        os << "]";
    }
    if (it->brother != nullptr) {
        os << ", ";
        Printh(it->brother, os);
        // os << "]";
    }
}

template <class T>
TNaryTree<T>::~TNaryTree()
{
    Clearh(root);
    std::cout << "Tree deleted." << std::endl;
}

#include "rhombus.h"
template class TNaryTree<Rhombus>;
template std::ostream &operator<<(std::ostream &os, const TNaryTree<Rhombus> &tree);