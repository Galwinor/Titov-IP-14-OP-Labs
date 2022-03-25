#include <iostream>
#include "OP2.2.h"
using namespace std;

int main()
{
	char cont = ' '; // Зберігає символ, за допомогою якого визначається чи дописати у файл
	do {
		input(cont); // Ввід даних у файл
		cout << "\nList of cars:\n";
		output("AutoBase.txt");  // Вивід змісту файла
		CreateList(); // Створення списку з автомобылямы проданими за останный мысяць
		UseedAuto(); // Вивеедення інформації про афтомобілі, які були продані більше ніж через рік після створення
		cout << "\nIf you want to add info. write '+': "; cin >> cont; // Чи хоче користувач дописати інформацію
	}while (cont == '+');
}

