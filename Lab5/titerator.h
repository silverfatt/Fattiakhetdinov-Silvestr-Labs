
#include <iostream>
#include <memory>

template <class item, class T>
class TIterator {
 public:
  TIterator(std::shared_ptr<item> n){ 
      node_ptr = n; 
  }

 T operator*() { return *(node_ptr->rhombus); }

  // std::shared_ptr<T> operator->() { return node_ptr->GetValue(); }

  void operator++() { node_ptr = node_ptr->GetNext(); }

  void GoToSon(){ //переход к сыну, если он есть
    if (node_ptr->son == nullptr){
      std::cout << "Node does not exist" << std::endl;
    } else {
      node_ptr = node_ptr->son;
    }
  }
  void GoToBro(){ //переход к брату, если он есть
    if (node_ptr->brother == nullptr){
      std::cout << "Node does not exist" << std::endl;
    } else {
      node_ptr = node_ptr->brother;
    }
  }

  bool operator==(TIterator const& i) { return node_ptr == i.node_ptr; }

  bool operator!=(TIterator const& i) { return !(*this == i); }

 private:
  std::shared_ptr<item> node_ptr;
};