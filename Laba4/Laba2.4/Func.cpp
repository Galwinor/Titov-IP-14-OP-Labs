#include "Numeral_16.h"
#include "Laba2.4.h"

int ConvertToDecimal(string Numeral) { // Перетворення с hex у decimal
	int Decimal = 0; // Десяткове число
	int number; 
	for (int i = 0; i < Numeral.size(); i++) { // Перебір символів
		number = getNumber(Numeral[i]); // Перетворення шістнадцяткових символів у десяткові
		Decimal += number * pow(16, Numeral.size() - i - 1); // Перетворення числа у десяткове
	}
	return Decimal;
}

int getNumber(char num) { // Перетворення шістнадцяткових символів у десяткові
	int number;
	switch (num) {
	case 'A': {number = 10; break; }
	case 'B': {number = 11; break; }
	case 'C': {number = 12; break; }
	case 'D': {number = 13; break; }
	case 'E': {number = 14; break; }
	case 'F': {number = 15; break; }
	default: number = num - '0';
	}
	return number;
}

string DecimalToHex(int Number) { // Перетворення десяткового числа у шістнадцяткове
	string Numeral;
	do
	{
		int r(Number % 16); // Ділення на шістнадцять і запис остачі у строку
		if (r > 9) { r += (int)'A' - 10; } // Перетворення чисел > 9 у букви
		else { r += (int)'0'; };
		Numeral += (char)r;
		Number /= 16;
	} while (Number);
	string NumeralReverse = "";
	for (int i = 0; i < Numeral.size(); i++) NumeralReverse += Numeral[Numeral.size() - i - 1]; // Перевернення рядка
	return NumeralReverse;
}

string DecimalToBinary(int Decimal) { // Перетворення десяткового числа у двійкове
	string Binary = "", BinaryReverse = "";
	while (Decimal > 1) { // Ділення на 2 і запис остачі у строку
		Binary += to_string(Decimal % 2);
		Decimal /= 2;
	}
	Binary += to_string(Decimal);
	for (int i = 0; i < Binary.size(); i++) BinaryReverse += Binary[Binary.size() - i - 1]; // Перевернення рядка
	while (BinaryReverse.find("0") == 0) BinaryReverse = BinaryReverse.substr(1); // Відкідання перших нулів якщо вони є
	return BinaryReverse;
}

Numeral_16 input() { // Вибір числа яке буде записуватись
	Numeral_16 A; // Обь'єкт класу
	char symbol;
	cout << "Rnter 'd' for Decimal and 'h' for Hex: "; cin >> symbol;
	if (symbol == 'd') { Numeral_16 B(funct<int>()); A = B; } // Виклик конструктора з параметром int
	else if (symbol == 'h') { Numeral_16 B(funct<string>()); A = B; }; // Виклик конструктора з параметром string
	return A;
}

template <typename T>
T funct() { // Введення числа
	cout << "Enter number: ";	
	T num;
	cin >> num;
	cout << endl;
	return num;
}