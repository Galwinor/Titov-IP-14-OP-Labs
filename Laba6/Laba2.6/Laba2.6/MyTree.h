#pragma once
#include <iostream>
using namespace std;
class MyTree // Дерево
{
	string key; // Інформаційне поле
	MyTree* Left, * Right; // Нащадки
public:
	MyTree(string kluch) { key = kluch; Left = NULL; Right = NULL; }
	void insertL(string); // Додати лівого нащадка
	void insertR(string); // Додати правого нащадка
	MyTree* getLeft() { return Left; } // Лівий нащадок
	MyTree* getRight() { return Right; } // Правий нащадок
	void setRoot(string k) { key = k; } // Змінити значення кореня
	string getRoot() { return key; } // Корінь
	bool isLeave(); // перевірка чи є піддерево листочком
	void setRight(MyTree* obj) { Right = obj; } // Змінити правого нащадка
	void setLeft(MyTree* obj) { Left = obj; } // Змінити лівого нащадка
};

