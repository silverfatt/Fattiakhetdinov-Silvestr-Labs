// Если какой-то вершины в tree_path не существует, 
//  то функция должна бросить исключение std::invalid_argument
// Если вершину нельзя добавить из за переполнения,
//  то функция должна бросить исключение std::out_of_range
#include "tnary_tree_item.h"

class TNaryTree {
 public:
  TNaryTree();                                                               //+
  TNaryTree(int n);                                                          //+
  void Update(Rhombus&& rhombus, std::string&& tree_path);                   //+
  void RemoveSubTree(std::string&& tree_path);                               //+
  const Rhombus& GetItem(const std::string&& tree_path);
  bool Empty();                                                              //+
  friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);  //
  virtual ~TNaryTree();  //

 private:
  void Clearh(TnaryTreeItem* it);  // helper
  void Printh(TnaryTreeItem* it, std::ostream& os) const;  // helper
  int N;
  TnaryTreeItem* root;
};