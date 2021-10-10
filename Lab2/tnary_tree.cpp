#include "tnary_tree.h"
 
TNaryTree::TNaryTree(int A){
  root = nullptr;
  N = A;
}
TNaryTree::TNaryTree(const TNaryTree& other) {
    N = other.N;
    TnaryTreeItem* copy = other.root;
    root = new TnaryTreeItem(copy->rhombus);
    TnaryTreeItem* it = root;
    if (copy->son != nullptr) {
        Copyh(it->son,copy->son);
    }
    if (copy->brother != nullptr) {
        Copyh(it->brother,copy->brother);
    }
}
void TNaryTree::Copyh(TnaryTreeItem*& it,TnaryTreeItem* copy) {
    it = new TnaryTreeItem(copy->rhombus);
    if (copy->son != nullptr) {
        Copyh(it->son,copy->son);
    }
    if (copy->brother != nullptr) {
        Copyh(it->brother,copy->brother);
    }
}
void TNaryTree::Update(Rhombus &&r, std::string &&tree_path=""){
if (tree_path == ""){
  if (root == nullptr) root = new TnaryTreeItem(r);
  else root->rhombus = r;
} else {
  TnaryTreeItem* it = root;
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
                it->son = new TnaryTreeItem(r);
            } else it->son->rhombus = r;
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            ++counter;
            if (counter > N) {
                throw std::out_of_range("Node cannot be added due to overflow");
            }
            if (it->brother == nullptr) {
                it->brother = new TnaryTreeItem(r);
            } else it->brother->rhombus = r;
        }
}
} 
bool TNaryTree::Empty() {
  return root == nullptr;
}

void TNaryTree::Clear(std::string &&tree_path){
  TnaryTreeItem* it;
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
            TnaryTreeItem* it_d = it->son;
            it->son = nullptr;
            Clearh(it_d);
        }
        if (tree_path[tree_path.size() - 1] == 'b') {
            TnaryTreeItem* it_d = it->brother;
            it->brother = nullptr;
            Clearh(it_d);
        }
    }
}

void TNaryTree::Clearh(TnaryTreeItem* it){
  if (it->brother != nullptr) Clearh(it->brother);
  if (it->son != nullptr) Clearh(it->son);
  delete it;
  return;
}

std::ostream& operator<<(std::ostream& os, const TNaryTree& tree){
os << "TREE: ";
TnaryTreeItem* it = tree.root;
tree.Printh(it, os);
return os;
}

void TNaryTree::Printh(TnaryTreeItem* it, std::ostream& os) const{
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
  TnaryTreeItem* it = root;
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

void TNaryTree::Areah(double& sum, TnaryTreeItem* it){
  if (it->brother != nullptr) Areah(sum, it->brother);
  if (it->son != nullptr) Areah(sum, it->son);
  sum = sum + it->rhombus.Area();
}

TNaryTree::~TNaryTree() {
  Clearh(root);
  std::cout << "Tree deleted.";
}
