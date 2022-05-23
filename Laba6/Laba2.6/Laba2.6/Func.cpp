#include "Laba2.6.h"
#include <stack>
#include <string>
using namespace std;

vector<string> rebuiltForm(string formula) { // Розділення формули по пробілу у вектор 
	vector<string> vect;
	int pos = 0;
	while (formula.find(' ') != string::npos) { // Розбиття формули по проблу
		pos = formula.find(' ');
		vect.push_back(formula.substr(0, pos));
		formula = formula.substr(pos + 1);
	}
	vect.push_back(formula);
	return vect;
}

MyTree* formTree(vector<string> formula) { // Створення дерева
	stack<MyTree*> myStack; // Створення стеку
	MyTree *Tree = new MyTree(""); // Нове дерево
	myStack.push(Tree); // Адреса дерева у стек
	MyTree* curTree = Tree;
	string determ = "+-*/"; // Роздільники
	for (string i : formula) { // Кожен елемент вектора
		if (i == "(") {
			curTree->insertL(""); // Створення нового нащадку
			myStack.push(curTree); // Зберігання адреси батька у стеці
			curTree = curTree->getLeft(); // Перехід до нащадка
		}
		else if (i == ")")
		{
			curTree = myStack.top(); // Повертаємося до батька
			myStack.pop(); // Видаляємо елемент зі стеку
		}
		else if (determ.find(i) != string::npos) { // Якщо знайдено роздільник
			curTree->setRoot(i); // Інформаційне поле елемента = роздільнику
			curTree->insertR(""); // Створення нового піддерева
			myStack.push(curTree); // Додавання адреси піддерева у стек
			curTree = curTree->getRight(); // Перехід до нащадка
		}
		else if (determ.find(i) == string::npos) { // Якщо це просто число
			curTree->setRoot(i); // Встановити інформаційне поле елемента рівним числу
			curTree = myStack.top(); // Повернення до балька
			myStack.pop(); // Видалення нащадку зі стеку
		}
	}
	return Tree;
}

void outputTree(const string& prefix, MyTree* tree, bool isLeft) { // Вивід дерева
	if (tree != NULL) {
		cout << prefix;
		cout << "'__";
		cout << tree->getRoot() << endl;
		outputTree(prefix + (isLeft ? "|   " : "    "), tree->getLeft(), true);
		outputTree(prefix + (isLeft ? "|   " : "    "), tree->getRight(), false);
	}
}

void changeTree(MyTree* tree) { // Обхід дерева в прямому порядку
	if (tree) {
		cnangeTree2(tree); // Розкриття дужок за потреби
		changeTree(tree->getLeft()); // Ліве піддерево
		changeTree(tree->getRight()); // Праве піддерево
	}
}

void cnangeTree2(MyTree* tree) { // Розкриття дужок
	MyTree* left = tree->getLeft(); // Лівий нащадок
	MyTree* right = tree->getRight(); // Правий нащадок
	string plus1 = "", plus2 = "", mult = "", symb = ""; // Елементи суми добутку і знак
	if (tree->getRoot() == "*") { // Якщо корень це множення
		if (left->isLeave()) // Якщо один з нащадків листок
			mult = left->getRoot();
		if (right->isLeave()) // Якщо один з нащадків листок
			mult = right->getRoot();
	}
	if (mult != "") { // Якщо є множення
		if (left->getRoot() == "+" || left->getRoot() == "-") { // Якщо один з нащадків це + або -
			symb = left->getRoot(); // Запис символу + або -
			if(left->getLeft()->isLeave()) // Перевірка чи є нащадки + або - листочками
				plus1 = left->getLeft()->getRoot();
			if (left->getRight()->isLeave())
				plus2 = left->getRight()->getRoot();
		}
		if (right->getRoot() == "+" || right->getRoot() == "-") { // Якщо один з нащадків це + або -
			symb = right->getRoot(); // Запис символу + або -
			if (right->getLeft()->isLeave()) // Перевірка чи є нащадки + або - листочками
				plus1 = right->getLeft()->getRoot();
			if (right->getRight()->isLeave())
				plus2 = right->getRight()->getRoot();
		}
	}
	if (mult != "" && plus1 != "" && plus2 != "") { // Якщо знайшли правильну структуру
		string formula = "( ( " + plus1 + " * " + mult + " ) " + symb + " ( " + plus2 + " * " + mult + " ) )"; // Нова формула
		string oldFormula = "( ( " + plus1 + " " + symb + " " + plus2 + " ) * " + mult + " )"; // Стара формула
		cout << oldFormula << " = " << formula << endl; 
		vector<string> vect = rebuiltForm(formula); // Нову формулу у вектор
		MyTree* newTree = new MyTree(""); 
		newTree = formTree(vect); // Створення дерева нової формули
		tree->setRoot(symb); // Заміна старої формули у дереві на нову
		tree->setRight(newTree->getRight());
		tree->setLeft(newTree->getLeft());
	}
}