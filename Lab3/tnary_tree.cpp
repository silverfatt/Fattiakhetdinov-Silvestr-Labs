#include "tnary_tree.h"
TNaryTree::TNaryTree(){
  root = nullptr;
  N = 3;
}
TNaryTree::TNaryTree(int A){
  root = nullptr;
  N = A;
}
const Rhombus& TNaryTree::GetItem(const std::string&& tree_path=""){
if (tree_path == ""){
  if (root == nullptr) throw std::invalid_argument("The node doesn't exist");
  else return root->rhombus;
} else {
  std::shared_ptr<TnaryTreeItem> it = root;
  int counter = 1;
  for (int i = 0; i<tree_path.size()-1; i++){
    if (tree_path[i] == 'b'){ 
      ++counter;
      it = it->brother;
      if (it == nullptr) {
        throw std::invalid_argument("The node doesn't exist"); 
    }
    }
    if (tree_path[i] == 'c'){
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
            } else return it->son->rhombus;
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            ++counter;
            if (counter > N) {
                throw std::out_of_range("The node doesn't exist"); 
            }
            if (it->brother == nullptr) {
                throw std::invalid_argument("The node doesn't exist");
            } else return it->brother->rhombus;
        }
}
};
void TNaryTree::Update(Rhombus &&r, std::string &&tree_path=""){
if (tree_path == ""){
  if (root == nullptr){
    std::shared_ptr<TnaryTreeItem> a(new TnaryTreeItem(r));
    root = a;
  }
  else root->rhombus = r;
} else {
  std::shared_ptr<TnaryTreeItem> it = root;
  int counter = 1;
  for (int i = 0; i<tree_path.size()-1; i++){
    if (tree_path[i] == 'b'){ 
      ++counter;
      it = it->brother;
      if (it == nullptr) {
        throw std::invalid_argument("The node doesn't exist");
    }
    }
    if (tree_path[i] == 'c'){
      counter = 1;
     it = it->son;
     if (it == nullptr) {
        throw std::invalid_argument("The node doesn't exist");
    }
    }
  }
  if (tree_path[tree_path.size() - 1] == 'c') {
            if (it->son == nullptr) {
              std::shared_ptr<TnaryTreeItem> it1(new TnaryTreeItem(r));
                it->son = it1;
            } else it->son->rhombus = r;
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            ++counter;
            if (counter > N) {
                throw std::out_of_range("Node cannot be added due to overflow");
            }
            if (it->brother == nullptr) {
              std::shared_ptr<TnaryTreeItem> it1(new TnaryTreeItem(r));
                it->brother = it1;
            } else it->brother->rhombus = r;
        }
}
} 
bool TNaryTree::Empty() {
  return root == nullptr;
}

void TNaryTree::RemoveSubTree(std::string &&tree_path){
  std::shared_ptr<TnaryTreeItem> it;
    if (tree_path == "") {
        Clearh(root);
    } else {
        it = root;
        for (int i = 0; i < tree_path.size() - 1; ++i) {
            if (tree_path[i] == 'b') {
                it = it->brother;
            }
            if (tree_path[i] == 'c') {
                it = it->son;
            }
        }
        if (tree_path[tree_path.size() - 1] == 'c') {
            std::shared_ptr<TnaryTreeItem> it_d = it->son;
            it->son = nullptr;
            Clearh(it_d);
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            std::shared_ptr<TnaryTreeItem> it_d = it->brother;
            it->brother = nullptr;
            Clearh(it_d);
        }
    }
}

void TNaryTree::Clearh(std::shared_ptr<TnaryTreeItem> it){
  if (it->brother != nullptr){
    std::shared_ptr<TnaryTreeItem> it_d1 = it->brother;
    it->brother = nullptr;
    Clearh(it_d1);
  }
  if (it->son != nullptr){
    std::shared_ptr<TnaryTreeItem> it_d2 = it->son;
    it->son = nullptr;
    Clearh(it_d2);
  }
  //delete it;
  return;
}

std::ostream& operator<<(std::ostream& os, const TNaryTree& tree){
os << "TREE: ";
std::shared_ptr<TnaryTreeItem> it = tree.root;
tree.Printh(it, os);
return os;
}

void TNaryTree::Printh(std::shared_ptr<TnaryTreeItem> it, std::ostream& os) const{
    os << it->rhombus.Area();
    if (it->son != nullptr) {
        os << ": [";
        Printh(it->son, os);
        os << "]";
    }
    if (it->brother != nullptr) {
        os << ", ";
        Printh(it->brother,os);
        //os << "]";
    }
}

TNaryTree::~TNaryTree() {
  Clearh(root);
  std::cout << "Tree deleted.";
}
