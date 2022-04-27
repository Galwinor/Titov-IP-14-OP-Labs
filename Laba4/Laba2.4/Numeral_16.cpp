#include "Numeral_16.h"
#include "Laba2.4.h"

Numeral_16::Numeral_16(int Num) { num = DecimalToHex(Num); }

string Numeral_16::ConverToBinaryOne() {// ������������ � ������� ������ ��������
	int Decimal = ConvertToDecimal(num); // ������������ � ���������
	return DecimalToBinary(Decimal); // ������������ � �������
}

string Numeral_16::ConverToBinaryTwo() { // ������������ � ������� ������ ��������
	string Binary = "", subBinary;
	int Number; 
	for (int i = 0; i < num.size(); i++) { // ������������ ����� ����� ���������������� ����� � �������
		Number = getNumber(num[i]); //������������ ����� � ���������
		subBinary = DecimalToBinary(Number); //������������ ����� � �������
		int sz = 4 - subBinary.size(); // ʳ������ ���� �� ����� �������� �� �������
		for (int j = 0; j < sz; j++) // ����������� ���� �� �������
			subBinary = "0" + subBinary;
		Binary += subBinary;
	}
	while (Binary.find("0") == 0)  Binary = Binary.substr(1);// ³�������� ������ ����
	return Binary;
}

Numeral_16 Numeral_16::operator++() { // �������������� ���������++
	int Decimal = ConvertToDecimal(num);// ������������ ���� � ���������
	num = DecimalToHex(++Decimal); // ������������� � ������������ ����� � ��������������
	return *this;
}

Numeral_16 Numeral_16::operator+(Numeral_16 obj) {// �������������� ���������+
	int DecimalFirst, DecimalSecond;
	DecimalFirst = ConvertToDecimal(num); // ������������ ������� ����� � ���������
	DecimalSecond = ConvertToDecimal(obj.getNumeral()); // ������������ ������� ����� � ���������
	num = DecimalToHex(DecimalFirst + DecimalSecond); // ��������� ����� � ������������ � ��������������
	return *this;
}

Numeral_16 Numeral_16::operator+=(int Number) {// �������������� ���������+=
	int Decimal = ConvertToDecimal(num);// ������������ ���� � ��������� 
	Decimal += Number; // ��������� �� ����� Number
	num = DecimalToHex(Decimal); // ������������ ����� � ��������������
	return *this;
}