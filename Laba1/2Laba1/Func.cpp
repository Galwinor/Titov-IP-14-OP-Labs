#include <iostream>
#include <string>
#include <fstream>
#include "2Laba1.h"

using namespace std;

void MoreInpt(string FileOne) {
    ofstream File(FileOne, ios::app); // Відкриття файла для запису
    string s;                    // Рядок, який пишеться у файл
    bool flag = true;            // Наявність символа кінця файла
    char endf = 20;              // Ctrl + T - символ завершення файла
    while (flag) {               // Виконується поки не знайшло символ завершення файла
        getline(cin, s);         // Запис рядка файла
        if (s.find(endf) != string::npos) {    // Пошук у рядку Ctrl + T
            flag = false;
            s.erase(s.find(endf), 1);          // Видалення символа
        }
        if (!s.empty())           // Запис рядку у файл, якщо рядок не пустий
            File << s << endl;
    }
    File.close();
}

void inputPlus(string FileOne, string FileTwo, int n) {
    ofstream File(FileTwo, ios::trunc);  // Очистка файла
    File.close();
    cout << endl << "FirstFile: " << endl;
    outFile(FileOne);
    newFile(FileOne, FileTwo, n);
    cout << endl << "SecondFile unsorted: " << endl;
    outFile(FileTwo);
    sort(FileTwo);
    cout << endl << "SecondFile sorted: " << endl;
    outFile(FileTwo);
}

void inFile(string FileOne) {
    string s;                    // Рядок, який пишеться у файл
    ofstream fIn(FileOne);       // Відкриття файла для запису
    bool flag = true;            // Наявність символа кінця файла
    char endf = 20;              // Ctrl + T - символ завершення файла
    while (flag) {               // Виконується поки не знайшло символ завершення файла
        getline(cin, s);         // Запис рядка файла
        if (s.find(endf) != string::npos) {    // Пошук у рядку Ctrl + T
            flag = false;
            s.erase(s.find(endf), 1);          // Видалення символа
        }
        if (!s.empty())           // Запис рядку у файл, якщо рядок не пустий
            fIn << s << endl;
    }
    fIn.close();
}

void outFile(string FileOne) {
    ifstream fOut(FileOne);// Відкриття файла для читання
    string s;
    while (!fOut.eof()) {  // Поки не дойшло до кінця файла
        getline(fOut, s);
        if (s[0] == ' ')   // Прибираємо пробіл на початку рядка
            s.erase(0, 1);
        cout << s << endl;
    }
    fOut.close();
}

void newFile(string FileOne, string FileTwo, int n) {
    int k = 0;                        // Кількість повторень кожного слова
    string word,                      // Кожне окреме слово
        str = " ",                    // Рядок першого файла
        st = "";                      // Рядок другого файла
    ifstream InOutFile(FileOne);      // Відкриття файла для читання
    getline(InOutFile, str);
    while (str != "") {               // Поки не дойшло до пустої строчки
        while (str.find(" ") != string::npos) {    //Пошук пробілів і виділення слів
            word = str.substr(0, str.find(" "));   //Перше слово рядка
            str.erase(0, str.find(" ") + 1);       //Видалення першого слова рядка
            k = count(FileOne, word);              //Підрахунок кількості повторень слова
            ifstream InFile(FileTwo);              // Відкриття файла для читання
            getline(InFile, st);                   // Вміст другого файла
            InFile.close();
            if (k < n && st.find(" " + word + " ") == string::npos && st.substr(0, st.find(" ")) != word) { // Перевірка чи є це слово в другому файлі і перевірка кількості повторень слова
                ofstream InFile(FileTwo, ios::app);
                InFile << word << " ";             // Запис слова в файл
                InFile.close();
            }
        }
        word = str.find(13) != string::npos ? str.substr(0, str.find(13)) : str; // Останнэ слово рядка
        k = count(FileOne, word);   // Кількість повторень останнього слова
        ifstream InFile(FileTwo);   // Відкриття файла для читання
        getline(InFile, st);
        InFile.close();
        if (k < n && st.find(" " + word + " ") == string::npos && st.substr(0, st.find(" ")) != word) {   // Перевірка чи є це слово в другому файлі і перевірка кількості повторень слова
            ofstream InFile(FileTwo, ios::app);   // Відкриття файла для запису
            InFile << word << " ";
            InFile.close();
        }
        getline(InOutFile, str);
    }
    InOutFile.close();
}

int count(string FileOne, string word) {
    ifstream OutFile(FileOne);  // Відкриття файла для читання
    int k = 0;   // Кількість повторень кожного слова
    string str,  // Рядок
        word1;   // Слово в рядку
    getline(OutFile, str);
    while (str != "") {
        while (str.find(" ") != string::npos) {
            word1 = str.substr(0, str.find(" "));  // Запис першого слово
            str.erase(0, str.find(" ") + 1);       // Видалення першого слова рядка
            if (word1 == word)    // Порівняння слів
                k++;   // Кількість слів + 1
        }
        word1 = str.find(13) != string::npos ? str.substr(0, str.find(13)) : str; // Останнє слово в рядку
        if (word1 == word)
            k++;
        getline(OutFile, str);
    }
    OutFile.close();
    return k;
}

void sort(string FileTwo) {
    int k = NumWords(FileTwo), // Кількість слів в рядку
        l = 0;                 // індекс масиву
    ifstream File(FileTwo);  // Відкриття файла для читання
    string* st = new string[k]; // Масив слів
    string word, // Кодне слово
        str,     // Рядок файла
        el;      // Зберігання елемента масиву для сортування
    getline(File, str);
    File.close();
    while (str.find(" ") != string::npos) {   // Запис слів з рядка у масив
        word = str.substr(0, str.find(" ")); // Запис першого слова рядка
        str.erase(0, str.find(" ") + 1);     // Видалення першого слова рядка
        st[l] = word;
        l++;  // Збільшення індекса
    }
    st[k - 1] = str; //Запис останнього слова рядка
    for (int i = 0; i < k; i++)   // Сортування бульбашкою
        for (int j = 0; j < k - i - 1; j++)
            if (size(st[j]) < size(st[j + 1])) { // Порівняння довжини слів
                el = st[j]; // Зберыгання значення елементу масива
                st[j] = st[j + 1]; // Заміна значення елементів
                st[j + 1] = el;    // Заміна значення елементів
            }
    ofstream File1(FileTwo);  // Відкриття файла для запису
    for (int i = 0; i < k; i++)  // Запис масива у файл
        File1 << st[i] << " ";
    File1.close();
    delete[]st;
}

int NumWords(string FileTwo) {
    int k = 0;  // Кількість слів у рядку
    ifstream File(FileTwo);  // Відкриття файла для читання
    string st;  // Рядок файла
    getline(File, st);
    for (int i = 0; i < size(st); i++) // Обрахунок кількосты пробілів
        if (st[i] == ' ')
            k++;
    File.close();
    return k + 1;
}