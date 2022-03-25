#pragma warning(disable:4996)
#include <string>
#include "OP2.3.h"
using namespace std;

Date Divide(string data) {
	Date dat; // Структура в яку записується дата
	dat.day = stoi(data.substr(0, data.find('.'))); // День
	dat.mounth = stoi(data.substr(data.find('.') + 1, data.rfind('.'))); // Місяць
	dat.year = stoi(data.substr(data.rfind('.') + 1)); // Рік
	return dat;
}

void output(vector<Product> tovar) {
	cout << "\nList of Products: \n";
	for (int i = 0; i < tovar.size(); i++)
		tovar[i].display(); // Вивід інформації про продукт
}

void Out_Of_Date(vector<Product> tovar) {
	cout << "\nOut of Date products: \n";
	string date = datta(); // Поточна дата
	int d1, d2; // Кількість днів в датах
	bool flag = true; // Чи є просрочені товари
	int day = stoi(date.substr(0, date.find('.'))); // Поточний день
	int mounth = stoi(date.substr(date.find('.') + 1, date.rfind('.'))); // Поточний місяць
	int year = stoi(date.substr(date.rfind('.') + 1)); // Поточний рік
	d1 = day + mounth * 31 + year * 365; // Кількість днів у даті
	for (int i = 0; i < tovar.size(); i++) {
		d2 = tovar[i].OutDate(); // Кількість днів у даті
		if (d2 < d1) { // Якщо товар просрочений
			tovar[i].display(); 
			flag = false;
		}
	}
	if (flag) cout << "No products.";
}

string datta() { // Поточна дата
	const time_t tm = time(nullptr);
	char buf[64];
	strftime(buf, sizeof(buf), "%d.%m.%Y", localtime(&tm));
	string date = buf;
	return date;
}

vector<Product> input() {
	bool flag = true; // Чи потрібно додати інформацію
	string name, // Назва продукту
		date1, date2, // Дати виготовленння і придатності
		fl; // Чи хоче користувач продовжувати
	vector <Product> Prod; // Масив для зберігання інформації про об'єкти
	Date RelDate, FinDate; // Дати виготовленння і придатності
	do {
		cout << "Enter Name: "; cin >> name;
		cout << "Enter Release Date with . like '10.10.2010': "; cin >> date1;
		RelDate = Divide(date1); // Виділення дня, місяця і року
		cout << "Enter Shelf Life Date with . like '10.10.2010': "; cin >> date2;
		FinDate = Divide(date2); // Виділення дня, місяця і року
		Product tovar(name, RelDate, FinDate); // Створення об'єкта класса
		Prod.push_back(tovar); // Запис об'єкта у вектор
		cout << "\nIf you want to continue, write '+': "; cin >> fl;// Чи хоче користувач продовжувати
		if (fl != "+") flag = false;
	} while (flag);
	return Prod;
}