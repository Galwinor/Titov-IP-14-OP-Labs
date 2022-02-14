#include <iostream>
#include <string>
#include <fstream>
#include "2Laba1.h"

using namespace std;

int main()
{
    string FileOne = "FirstFile.txt", FileTwo = "SecondFile.txt";
    int n;  // Максимальна кількісь повторюваних слів
    bool flag = true;  // Чи треба дописувати текст
    char a;
    cout << "Enter n: "; cin >> n;
    cout << "Enter text(Ctrl + T to finish): " << endl;
    inFile(FileOne);                              
    inputPlus(FileOne, FileTwo, n); 
    while (flag) {  // Дописування у кінець файла
        cout << endl << "Enter '+' if you want to continue: "; cin >> a;
        if (a == '+') {
            cout << "Enter text(Ctrl + T to finish): " << endl;
            MoreInpt(FileOne);
            inputPlus(FileOne, FileTwo, n);
        }
        else
            flag = false;   // Не дописувати
    }   
}