#include <string>
#include "Laba2.6.h"
using namespace std;

int main()
{
    // Приклади для програми: 
    // ( ( 2 + ( ( 2 + 3 ) * 4 ) ) - ( 5 * ( 4 - 6 ) ) )
    // ( ( 2 + 7 ) * 4 )
    // ( 6 - ( ( 7 + 0 ) * 9 ) )
    setlocale(LC_ALL, "Russian");
    string formula; // Введення формули
    cout << "Введiть формулу, КОЖНА операцiя роздiляється дужками, символи вiдокремлюються пробiлами, приклад '( ( 7 - 9 ) * 0 )':\n"; 
    getline(cin, formula);
    vector<string> vect = rebuiltForm(formula); // Розділення формули по пробілу у вектор 
    MyTree* tree = formTree(vect);  // Формування дерева з вектора
    cout << "Strt tree: " << endl;
    outputTree("", tree, false); // Вивід дерева
    changeTree(tree); // Відкритя дужок
    cout << "Final tree: \n";
    outputTree("", tree, false); // Вивід дерева
    delete tree;
}