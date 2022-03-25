#pragma warning(disable:4996)
#define Sal a.SaleRelease
#define Rel a.Release
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "OP2.2.h"
using namespace std;

void input(char cont) {
	char k; // Зберігає символ, за допомогою якого визначається чи продовжувати запис
	AutoBase a; // Змінна, що зберігає інформація про машину
	string Read; // Змінна для читання з консолі
	ofstream In; 
	if (cont == '+') { In.open("AutoBase.txt", ios::binary | ios::app); cin.ignore(); }// Відкриття файла для дозапису
	else In.open("AutoBase.txt", ios::binary); // Відкриття файла для запису
	do {
		cout << "Enter name of car: "; getline(cin, Read); // Ім'я машини
		strcpy(a.Name, data(Read));
		cout << "Enter Release Date with a point '10.10.2010': "; getline(cin, Read); // Дата виготовлення
		a = Divide(a, Read, 0); // Розділення дати у форматі string на змінні формату int
		cout << "Enter Sale Release Date with a point '10.10.2010': "; getline(cin, Read); // Дата продажу
		a = Divide(a, Read, 1); // Розділення дати у форматі string на змінні формату int
		cout << "\nEnter '+' in case you want to contnue: "; cin >> k; // Чи хоче користувач продовжувати
		In.write((char*)&a, sizeof(AutoBase)); // Запис у файл даних про машину
		cin.ignore();
	} while (k == '+');
	In.close();
}

AutoBase Divide(AutoBase a, string Read, bool b) {
	int pos1 = Read.find('.'); // Позиція першої крапки
	int pos2 = Read.rfind('.'); // Позиція другої крапки
	if (!b) {
		Rel.day = stoi(Read.substr(0, pos1)); // Запис дня у змінну
		Rel.mounth = stoi(Read.substr(pos1 + 1, pos2)); // Запис місяця у змінну
		Rel.year = stoi(Read.substr(pos2 + 1)); // Запис року у змінну
	}
	else {
		Sal.day = stoi(Read.substr(0, pos1)); // Запис дня у змінну
		Sal.mounth = stoi(Read.substr(pos1 + 1, pos2)); // Запис місяця у змінну
		Sal.year = stoi(Read.substr(pos2 + 1)); // Запис року у змінну
	}
	return a;
}

void CreateList() {
	string date = datta(); // Поточна дата
	ifstream Out("Autobase.txt", ios::binary); // Відкриття файла для читання
	ofstream In("OneMounth.txt", ios::binary); // Відкриття файла для запису
	AutoBase a; // Змінна, що зберігає інформація про машину
	bool flag = true; // Наявність машин, що відповідають умовам
	int day = stoi(date.substr(0, date.find('.'))); // Поточний день
	int mounth = stoi(date.substr(date.find('.') + 1, date.rfind('.'))); // Поточний місяць
	int year = stoi(date.substr(date.rfind('.') + 1)); // Поточний рік
	int d1 = day + mounth * 31 + year * 365; // Поточна дата у днях
	int d2; // Дата продажу у днях
	while (Out.read((char*)&a, sizeof(AutoBase))) { // Читання з файлу
		d2 = Sal.day + Sal.mounth * 31 + Sal.year * 365;
		if (d2 + 31 >= d1) { // Мащини, що були продані в останній місяць
			In.write((char*)&a, sizeof(AutoBase)); // Запис у файл
			flag = false;
		}
	}
	In.close();
	Out.close();
	cout << "\nCars on Sale in last mounth: \n";
	if (flag) cout << "No cars.\n"; // Якщо таких машин нема
	else output("OneMounth.txt");// Вивід зміста файла
}

string datta() { // Поточна дата
	const time_t tm = time(nullptr);
	char buf[64];
	strftime(buf, sizeof(buf), "%d.%m.%Y", localtime(&tm));
	string date = buf; 
	return date;
}

void output(string name) {
	ifstream Out(name, ios::binary); // Відкриття файла для читання
	AutoBase a; // Змінна, що зберігає інформація про машину
	while (Out.read((char*)&a, sizeof(AutoBase))) // Читання з файла
		printf("Name: %-15s Release date: %02i.%02i.%-9i Sale Release date: %02i.%.02i.%-9i\n",
			a.Name, Rel.day, Rel.mounth, Rel.year, Sal.day, Sal.mounth, Sal.year);
	Out.close();
}

void UseedAuto() {
	cout << "\nSaled after >1 year after Release: \n";
	ifstream Out("Autobase.txt", ios::binary); // Відкриття файла для читання
	AutoBase a; // Змінна, що зберігає нформація про машину
	bool flag = true; // Наявність машин, що відповідають умовам
	int d1, d2; // Дати у днях
	while (Out.read((char*)&a, sizeof(AutoBase))) {// Читання з файла
		d1 = Sal.day + Sal.mounth * 31 + Sal.year * 365; // Дата виготовлення
		d2 = Rel.day + Rel.mounth * 31 + Rel.year * 365; // Дата продажу
		if (d2 + 365 < d1) { // Машини, що були продані більше ніж через рік після створення
			printf("Name: %-15s Release date: %02i.%02i.%-9i Sale Release date: %02i.%.02i.%-9i\n",
				a.Name, Rel.day, Rel.mounth, Rel.year, Sal.day, Sal.mounth, Sal.year);
			flag = false;
		}
	}
	if (flag) cout << "No cars.\n"; // Якщо таких машин нема
	Out.close();
}