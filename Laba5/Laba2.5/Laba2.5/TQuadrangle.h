#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Coordiantes { // Структура координат
	double x, y;
};

class TQuadrangle
{
	double countPerim(); // Обрахунок периметру
protected:
	Coordiantes V[4]; // Координати вершин
	double perimeter; // Периметр
	double area; // Площа
	const string type; // Тип фігури
	virtual double countArea() = 0; // Обрахунок площі
public:
	TQuadrangle(Coordiantes [4], string); // Конструктор
	void getAllInfo(); // Вивід інформації про обьєкт
	string getType() { return type; } // Гетер типу
	double getPer() { return perimeter; } // Гетер периметру
	double getArea() { return area; } // Гетер площі
};