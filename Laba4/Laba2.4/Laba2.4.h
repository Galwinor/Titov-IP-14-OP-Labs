#pragma once
#include <iostream>
#include <string>
#include "Numeral_16.h"
using namespace std;

int ConvertToDecimal(string); // ������������ � hex � decimal
string DecimalToHex(int); // ������������ ����������� ����� � ��������������
string DecimalToBinary(int); // ������������ ����������� ����� � �������
int getNumber(char); // ������������ ��������������� ������� � ��������
Numeral_16 input(); // ���� ����� ��� ���� ������������
template <typename T>
T funct(); // �������� �����