#include "Laba2.5.h"
using namespace std;

int main()
{
	int n; // Кількість фігур
	vector<TQuadrangle*> figurs;
	cout << "Enter number of figuers: "; cin >> n;
	figurs = input(n); // Введення фігур
	output(figurs); // Вивід фігур
	calculateSum(figurs); // Обрахунок і вивід суми площ і периметрів
}