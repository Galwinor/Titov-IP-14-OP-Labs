#pragma once
#include <string>
#include <iostream>
using namespace std;

class Numeral_16 // ���� ���������������� �����
{
	string num; // س������������ �����
public:
	Numeral_16() {};// ������� �����������
	Numeral_16(string Num) { num = Num; }// ���������� ���� ������ string
	Numeral_16(int Num);// ���������� ���� ������ int
	string ConverToBinaryOne();//������������ ����� � ������ ������ ��������
	string ConverToBinaryTwo();//������������ ����� � ������ ������ ��������
	Numeral_16 operator++();// �������������� ���������� ����������
	Numeral_16 operator+(Numeral_16);// �������������� ��������� +
	Numeral_16 operator+=(int);// �������������� ��������� +=
	string getNumeral() { return num; };// ��������� �����
};