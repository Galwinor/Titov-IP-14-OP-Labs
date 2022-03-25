#pragma once
#include "Product.h"
using namespace std;

Date Divide(string); // Розділення дати на день рік і місяць
void output(vector<Product>); // Вивід інформації про продукти
void Out_Of_Date(vector<Product>); // Визначення продуктів, в яких закінчився срок придатності
string datta(); // Визначення поточної дати
vector<Product> input(); // Введення інформації про продукти