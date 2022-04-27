#include "Numeral_16.h"
#include "Laba2.4.h"

int ConvertToDecimal(string Numeral) { // ������������ � hex � decimal
	int Decimal = 0; // ��������� �����
	int number; 
	for (int i = 0; i < Numeral.size(); i++) { // ������ �������
		number = getNumber(Numeral[i]); // ������������ ��������������� ������� � ��������
		Decimal += number * pow(16, Numeral.size() - i - 1); // ������������ ����� � ���������
	}
	return Decimal;
}

int getNumber(char num) { // ������������ ��������������� ������� � ��������
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

string DecimalToHex(int Number) { // ������������ ����������� ����� � ��������������
	string Numeral;
	do
	{
		int r(Number % 16); // ĳ����� �� ����������� � ����� ������ � ������
		if (r > 9) { r += (int)'A' - 10; } // ������������ ����� > 9 � �����
		else { r += (int)'0'; };
		Numeral += (char)r;
		Number /= 16;
	} while (Number);
	string NumeralReverse = "";
	for (int i = 0; i < Numeral.size(); i++) NumeralReverse += Numeral[Numeral.size() - i - 1]; // ������������ �����
	return NumeralReverse;
}

string DecimalToBinary(int Decimal) { // ������������ ����������� ����� � �������
	string Binary = "", BinaryReverse = "";
	while (Decimal > 1) { // ĳ����� �� 2 � ����� ������ � ������
		Binary += to_string(Decimal % 2);
		Decimal /= 2;
	}
	Binary += to_string(Decimal);
	for (int i = 0; i < Binary.size(); i++) BinaryReverse += Binary[Binary.size() - i - 1]; // ������������ �����
	while (BinaryReverse.find("0") == 0) BinaryReverse = BinaryReverse.substr(1); // ³������� ������ ���� ���� ���� �
	return BinaryReverse;
}

Numeral_16 input() { // ���� ����� ��� ���� ������������
	Numeral_16 A; // ���'��� �����
	char symbol;
	cout << "Rnter 'd' for Decimal and 'h' for Hex: "; cin >> symbol;
	if (symbol == 'd') { Numeral_16 B(funct<int>()); A = B; } // ������ ������������ � ���������� int
	else if (symbol == 'h') { Numeral_16 B(funct<string>()); A = B; }; // ������ ������������ � ���������� string
	return A;
}

template <typename T>
T funct() { // �������� �����
	cout << "Enter number: ";	
	T num;
	cin >> num;
	cout << endl;
	return num;
}