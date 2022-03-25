#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Date { // Дата
	int day;
	int mounth;
	int year;
};

class Product { // Продукт
	string name; // Назва продукту
	Date Release; // Дата виготовлення
	Date FinishD; // Дата закінчення сроку придатності
public:
	Product(string Name, Date Rel, Date Fin) { name = Name; Release = Rel; FinishD = Fin; } 
	void display(); // Вивід інформації про продукт
	int OutDate(); // Повертає дату закінчення сроку придатності
};