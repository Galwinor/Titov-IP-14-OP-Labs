#include "Numeral_16.h"
#include "Laba2.4.h"

Numeral_16::Numeral_16(int Num) { num = DecimalToHex(Num); }

string Numeral_16::ConverToBinaryOne() {// Перетворення у двійкове першим способом
	int Decimal = ConvertToDecimal(num); // Перетворення у десяткове
	return DecimalToBinary(Decimal); // перетворення у двійкове
}

string Numeral_16::ConverToBinaryTwo() { // Перетворення у двійкове другим способом
	string Binary = "", subBinary;
	int Number; 
	for (int i = 0; i < num.size(); i++) { // Перетворення кожної цифри шістнадцяткового числа у двійкове
		Number = getNumber(num[i]); //Перетворення цифри у десяткове
		subBinary = DecimalToBinary(Number); //Перетворення цифри у двійкове
		int sz = 4 - subBinary.size(); // Кількість нулів які треба дописати на початок
		for (int j = 0; j < sz; j++) // Дописування нулів на початок
			subBinary = "0" + subBinary;
		Binary += subBinary;
	}
	while (Binary.find("0") == 0)  Binary = Binary.substr(1);// Відкидання перших нулів
	return Binary;
}

Numeral_16 Numeral_16::operator++() { // Перевантаження оператора++
	int Decimal = ConvertToDecimal(num);// Перетворення числ у десятокве
	num = DecimalToHex(++Decimal); // Інкрементація і перетворення числа у шістнадцяткове
	return *this;
}

Numeral_16 Numeral_16::operator+(Numeral_16 obj) {// Перевантаження оператора+
	int DecimalFirst, DecimalSecond;
	DecimalFirst = ConvertToDecimal(num); // Перетворення першого числа у десяткове
	DecimalSecond = ConvertToDecimal(obj.getNumeral()); // Перетворення другого числа у десяткове
	num = DecimalToHex(DecimalFirst + DecimalSecond); // Додавання чисел і перетворення у шістнадцяткове
	return *this;
}

Numeral_16 Numeral_16::operator+=(int Number) {// Перевантаження оператора+=
	int Decimal = ConvertToDecimal(num);// Перетворення числ у десятокве 
	Decimal += Number; // Додавання до нього Number
	num = DecimalToHex(Decimal); // Перетворення числа у шістнадцяткове
	return *this;
}