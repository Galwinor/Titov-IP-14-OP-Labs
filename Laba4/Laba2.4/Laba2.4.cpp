#include "Numeral_16.h"
#include "Laba2.4.h"
int main()
{
	Numeral_16 N1(input()); // Ввід першого числа
	Numeral_16 N2(input()); // Ввід другого числа
	Numeral_16 N3(input()); // Ввід третього числа
	int n; // Число яке буде додаватися до N2
	cout << "You entered:\nN1: " << N1.getNumeral() << "\nN2: " << N2.getNumeral() << "\nN3: " << N3.getNumeral() << endl; // Вивід чисел 
	++N1; // Інкрементація
	cout << "\n++N1 = " << N1.getNumeral() << endl;
	cout << "\nEnter n: "; cin >> n;
	N2 += n; // Збільшення на n
	cout << "N2 + " << n << " = " << N2.getNumeral();
	N3 = N1 + N2; // Сума чисел
	cout << "\nN1 + N2 = " << N3.getNumeral();
	cout << "\n\nN3 into binary(first way): " << N3.ConverToBinaryOne();
	cout << "\nN3 into binary(second way): " << N3.ConverToBinaryTwo();
}