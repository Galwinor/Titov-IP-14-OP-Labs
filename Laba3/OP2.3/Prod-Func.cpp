#include "Product.h"
#include <string>

using namespace std;

void Product::display() { // Виведення інформації про продукт
	printf("Name: %-15s Release date: %02i.%02i.%-9i Shelf Life date: %02i.%.02i.%-9i\n",
		name.c_str(), Release.day, Release.mounth, Release.year, FinishD.day, FinishD.mounth, FinishD.year);
}

int Product::OutDate() {
	return FinishD.day + FinishD.mounth*31 + FinishD.year*365; // Кількість днів у даті
}