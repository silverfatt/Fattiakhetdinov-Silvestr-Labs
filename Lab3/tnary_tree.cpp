#include "tnary_tree.h"
 
TNaryTree::TNaryTree(int A){
  root = nullptr;
  N = A;
}
TNaryTree::TNaryTree(const TNaryTree& other) {
    N = other.N;
    std::shared_ptr<TnaryTreeItem> copy_it = other.root;
    std::shared_ptr<TnaryTreeItem> it1(new TnaryTreeItem(copy_it->rhombus));
    root = it1;
    std::shared_ptr<TnaryTreeItem> it = root;
    if (copy_it->son != nullptr) {
        Copyh(it->son,copy_it->son);
    }
    if (copy_it->brother != nullptr) {
        Copyh(it->brother,copy_it->brother);
    }
}
void TNaryTree::Copyh(std::shared_ptr<TnaryTreeItem>& it,std::shared_ptr<TnaryTreeItem> copy_it) { 
    std::shared_ptr<TnaryTreeItem> it1(new TnaryTreeItem(copy_it->rhombus));
    it = it1;
    if (copy_it->son != nullptr) {
        Copyh(it->son,copy_it->son);
    }
    if (copy_it->brother != nullptr) {
        Copyh(it->brother,copy_it->brother);
    }
}
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

void TNaryTree::Clear(std::string &&tree_path){
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
  if (it->brother != nullptr) Clearh(it->brother);
  if (it->son != nullptr) Clearh(it->son);
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


double TNaryTree::Area(std::string&& tree_path){
  double sum = 0;
  if(tree_path == "") Areah(sum, root); else{
  std::shared_ptr<TnaryTreeItem> it = root;
    for(int i = 0; i<tree_path.size(); i++){
    if (tree_path[i] == 'b') it = it->brother;
    if (tree_path[i] == 'c') it = it->son;
  }
  if (tree_path[tree_path.size() - 1] == 'c') {
            Areah(sum, it->son);
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            Areah(sum, it->brother);
        }
  }
  return sum;
}

void TNaryTree::Areah(double& sum, std::shared_ptr<TnaryTreeItem> it){
  if (it->brother != nullptr) Areah(sum, it->brother);
  if (it->son != nullptr) Areah(sum, it->son);
  sum = sum + it->rhombus.Area();
}

TNaryTree::~TNaryTree() {
  Clearh(root);
  std::cout << "Tree deleted.";
}
