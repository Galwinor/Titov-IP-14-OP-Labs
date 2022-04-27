#pragma once
#include <iostream>
#include <string>
#include "Numeral_16.h"
using namespace std;

int ConvertToDecimal(string); // Перетворення с hex у decimal
string DecimalToHex(int); // Перетворення десяткового числа у шістнадцяткове
string DecimalToBinary(int); // Перетворення десяткового числа у двійкове
int getNumber(char); // Перетворення шістнадцяткових символів у десяткові
Numeral_16 input(); // Вибір числа яке буде записуватись
template <typename T>
T funct(); // Введення числа