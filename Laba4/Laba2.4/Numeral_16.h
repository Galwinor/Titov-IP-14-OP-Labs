#pragma once
#include <string>
#include <iostream>
using namespace std;

class Numeral_16 // Клас шістнадцяткового числа
{
	string num; // Шістнадцяткове число
public:
	Numeral_16() {};// Порожній конструктор
	Numeral_16(string Num) { num = Num; }// Конструтор який приймає string
	Numeral_16(int Num);// Конструтор який приймає int
	string ConverToBinaryOne();//Перетворення числа у двійкое першим способом
	string ConverToBinaryTwo();//Перетворення числа у двійкое другим способом
	Numeral_16 operator++();// перевантаження опретатора інкремента
	Numeral_16 operator+(Numeral_16);// перевантаження оператора +
	Numeral_16 operator+=(int);// перевантаження оператора +=
	string getNumeral() { return num; };// Отримання числа
};