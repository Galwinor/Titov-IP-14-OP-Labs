#include "Laba2.5.h"
#include "parallelogram.h"
#include "square.h"
#include <string>
using namespace std;
TQuadrangle* createItem(Coordiantes V[4]) { // Створення обьєкту
	Coordiantes Sides[4];
	for (int i = 0; i < 4; i++) { // Обрахунок координат викторів сторін
		Sides[i].x = V[(i + 1) % 4].x - V[i].x;
		Sides[i].y = V[(i + 1) % 4].y - V[i].y;
	}
	if (isColiniar(Sides[0], Sides[2]) && isColiniar(Sides[1], Sides[3])) { // Перевірка на колінеарність
		if (Sides[0].x * Sides[1].x + Sides[0].y * Sides[1].y == 0) { // Перевірка на перпендикулярність
			if (isEquel(Sides[0], Sides[1])) // Перевірка на рівність
				return new square(V); // Створення квадрату
			return new rectangle(V); // Створення прямокутника
		}
		return new parallelogram(V); // Створення паралелограма
	}
	return NULL;
}

vector<TQuadrangle*> input(int n) { // Ввід фігур
	vector<TQuadrangle*> Figuers(n); // Вектор фігур
	Coordiantes V[4]; // Координати вершин
	bool flag = true; // Індикатор чи правильно записана фігура
	string cord; // Координати
	for (int i = 0; i < n; i++) { // Запис n фігкр
		while (flag) {
			cout << "Enter coords of 4 vertices so that thay are creating rectangle/square/parallelogram in format 'x,y':\n";
			for (int j = 0; j < 4; j++) { // Запис координат
				cout << "Enter " << j + 1 << ": "; cin >> cord;
				V[j].x = stod(cord.substr(0, cord.find(',')));
				V[j].y = stod(cord.substr(cord.find(',') + 1));
			}
			Figuers[i] = createItem(V); // Створення обьєкту
			if (Figuers[i] == NULL) cout << "\nWrong format!\n"; // Чи правильно обьєкт записан
			else flag = false;
		}
		flag = true; 
	}
	return Figuers;
}

bool isColiniar(Coordiantes Side1, Coordiantes Side2) { // Перевірка на колініарність
	double k1, k2;
	k1 = double(Side1.x) * Side2.y; // Коофіцієнт 1
	k2 = double(Side1.y) * Side2.x; // Коофіцієнт 2
	return k1 == k2;
}

bool isEquel(Coordiantes Side1, Coordiantes Side2) {
	double len1, len2;
	len1 = sqrt(pow(Side1.x, 2) + pow(Side1.y, 2)); // Довжина сторони 1
	len2 = sqrt(pow(Side2.x, 2) + pow(Side2.y, 2)); // Довжина сторони 2
	return len1 == len2;
}

void output(vector<TQuadrangle*> Obj) {
	cout << "\nAll your figures:\n";
	for (int i = 0; i < Obj.size(); i++) { // Вивід інформації про фігури
		cout << i + 1 << ". ";
		Obj[i]->getAllInfo();
	}
}

void calculateSum(vector<TQuadrangle*> Obj) { // Обрахунок суми площ і периметру
	double area = 0, perimetr = 0;
	string type;
	for (TQuadrangle* i : Obj) {
		type = i->getType(); // Тип фігури
		if (type == "Square" || type == "Rectangle") area += i->getArea(); // + площа
		else perimetr += i->getPer(); // + периметр
	}
	cout << "\nSum the areas(aquares, rectangles) = " << area << "\nSum of perimeters(parallelograms = " << perimetr;
}