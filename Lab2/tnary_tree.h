// Если какой-то вершины в tree_path не существует, 
//  то функция должна бросить исключение std::invalid_argument
// Если вершину нельзя добавить из за переполнения,
//  то функция должна бросить исключение std::out_of_range
#include "tnary_tree_item.h"

class TNaryTree {
public:
// Инициализация дерева с указанием размера
TNaryTree(int n); //+

// Полное копирование дерева 
TNaryTree(const TNaryTree& other); //
void Copyh(TnaryTreeItem*& it1, TnaryTreeItem* it2);

// Добавление или обновление вершины в дереве согласно заданному пути.
// Путь задается строкой вида: "cbccbccc", 
// где 'c' - старший ребенок, 'b' - младший брат
// последний символ строки - вершина, которую нужно добавить или обновить.
// Пустой путь "" означает добавление/обновление корня дерева.
void Update(Rhombus &&rhombus, std::string &&tree_path); //+

// Удаление поддерева
void Clear(std::string &&tree_path);//+
void Clearh(TnaryTreeItem* it);//helper

// Проверка наличия в дереве вершин
bool Empty();//+

// Подсчет суммарной площади поддерева
double Area(std::string &&tree_path);//+
void Areah(double& sum, TnaryTreeItem* it);//helper+

// Вывод дерева в формате вложенных списков, где каждый вложенный список является:
// "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры
friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);//
void Printh(TnaryTreeItem* it, std::ostream& os) const; //helper

virtual ~TNaryTree();//
  int N;
  TnaryTreeItem* root;

};