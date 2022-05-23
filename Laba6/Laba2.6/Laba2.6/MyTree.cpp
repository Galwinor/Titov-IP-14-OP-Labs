#include "MyTree.h"
using namespace std;

void MyTree::insertL(string key) { // Додавання лівого нащадка
	if (this->Left == NULL) // Якщо немає нащадка - створити
		this->Left = new MyTree(key);
	else {
		MyTree* p = new MyTree(key); // Якщо є нащадок - зробити новий елемент батьком існуючого нащадка
		p->Left = this->Left;
		this->Left = p;
	}
}

void MyTree::insertR(string key) { // Додавання правого нащадка
	if (this->Right == NULL) // Якщо немає нащадка - створити
		this->Right = new MyTree(key);
	else {	
		MyTree* p = new MyTree(key); // Якщо є нащадок - зробити новий елемент батьком існуючого нащадка
		p->Right = this->Right;
		this->Right = p;
	}
}

bool MyTree::isLeave() { // перевірка чи є піддерево листочком
	if (this->Left == NULL && this->Right == NULL) // Чи є нащадки
		return true;
	return false;
}
