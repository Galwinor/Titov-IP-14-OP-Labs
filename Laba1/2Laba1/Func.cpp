#include <iostream>
#include <string>
#include <fstream>
#include "2Laba1.h"

using namespace std;

void MoreInpt(string FileOne) {
    ofstream File(FileOne, ios::app); // ³������� ����� ��� ������
    string s;                    // �����, ���� �������� � ����
    bool flag = true;            // �������� ������� ���� �����
    char endf = 20;              // Ctrl + T - ������ ���������� �����
    while (flag) {               // ���������� ���� �� ������� ������ ���������� �����
        getline(cin, s);         // ����� ����� �����
        if (s.find(endf) != string::npos) {    // ����� � ����� Ctrl + T
            flag = false;
            s.erase(s.find(endf), 1);          // ��������� �������
        }
        if (!s.empty())           // ����� ����� � ����, ���� ����� �� ������
            File << s << endl;
    }
    File.close();
}

void inputPlus(string FileOne, string FileTwo, int n) {
    ofstream File(FileTwo, ios::trunc);  // ������� �����
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
    string s;                    // �����, ���� �������� � ����
    ofstream fIn(FileOne);       // ³������� ����� ��� ������
    bool flag = true;            // �������� ������� ���� �����
    char endf = 20;              // Ctrl + T - ������ ���������� �����
    while (flag) {               // ���������� ���� �� ������� ������ ���������� �����
        getline(cin, s);         // ����� ����� �����
        if (s.find(endf) != string::npos) {    // ����� � ����� Ctrl + T
            flag = false;
            s.erase(s.find(endf), 1);          // ��������� �������
        }
        if (!s.empty())           // ����� ����� � ����, ���� ����� �� ������
            fIn << s << endl;
    }
    fIn.close();
}

void outFile(string FileOne) {
    ifstream fOut(FileOne);// ³������� ����� ��� �������
    string s;
    while (!fOut.eof()) {  // ���� �� ������ �� ���� �����
        getline(fOut, s);
        if (s[0] == ' ')   // ��������� ����� �� ������� �����
            s.erase(0, 1);
        cout << s << endl;
    }
    fOut.close();
}

void newFile(string FileOne, string FileTwo, int n) {
    int k = 0;                        // ʳ������ ��������� ������� �����
    string word,                      // ����� ������ �����
        str = " ",                    // ����� ������� �����
        st = "";                      // ����� ������� �����
    ifstream InOutFile(FileOne);      // ³������� ����� ��� �������
    getline(InOutFile, str);
    while (str != "") {               // ���� �� ������ �� ����� �������
        while (str.find(" ") != string::npos) {    //����� ������ � �������� ���
            word = str.substr(0, str.find(" "));   //����� ����� �����
            str.erase(0, str.find(" ") + 1);       //��������� ������� ����� �����
            k = count(FileOne, word);              //ϳ�������� ������� ��������� �����
            ifstream InFile(FileTwo);              // ³������� ����� ��� �������
            getline(InFile, st);                   // ���� ������� �����
            InFile.close();
            if (k < n && st.find(" " + word + " ") == string::npos && st.substr(0, st.find(" ")) != word) { // �������� �� � �� ����� � ������� ���� � �������� ������� ��������� �����
                ofstream InFile(FileTwo, ios::app);
                InFile << word << " ";             // ����� ����� � ����
                InFile.close();
            }
        }
        word = str.find(13) != string::npos ? str.substr(0, str.find(13)) : str; // ������� ����� �����
        k = count(FileOne, word);   // ʳ������ ��������� ���������� �����
        ifstream InFile(FileTwo);   // ³������� ����� ��� �������
        getline(InFile, st);
        InFile.close();
        if (k < n && st.find(" " + word + " ") == string::npos && st.substr(0, st.find(" ")) != word) {   // �������� �� � �� ����� � ������� ���� � �������� ������� ��������� �����
            ofstream InFile(FileTwo, ios::app);   // ³������� ����� ��� ������
            InFile << word << " ";
            InFile.close();
        }
        getline(InOutFile, str);
    }
    InOutFile.close();
}

int count(string FileOne, string word) {
    ifstream OutFile(FileOne);  // ³������� ����� ��� �������
    int k = 0;   // ʳ������ ��������� ������� �����
    string str,  // �����
        word1;   // ����� � �����
    getline(OutFile, str);
    while (str != "") {
        while (str.find(" ") != string::npos) {
            word1 = str.substr(0, str.find(" "));  // ����� ������� �����
            str.erase(0, str.find(" ") + 1);       // ��������� ������� ����� �����
            if (word1 == word)    // ��������� ���
                k++;   // ʳ������ ��� + 1
        }
        word1 = str.find(13) != string::npos ? str.substr(0, str.find(13)) : str; // ������ ����� � �����
        if (word1 == word)
            k++;
        getline(OutFile, str);
    }
    OutFile.close();
    return k;
}

void sort(string FileTwo) {
    int k = NumWords(FileTwo), // ʳ������ ��� � �����
        l = 0;                 // ������ ������
    ifstream File(FileTwo);  // ³������� ����� ��� �������
    string* st = new string[k]; // ����� ���
    string word, // ����� �����
        str,     // ����� �����
        el;      // ��������� �������� ������ ��� ����������
    getline(File, str);
    File.close();
    while (str.find(" ") != string::npos) {   // ����� ��� � ����� � �����
        word = str.substr(0, str.find(" ")); // ����� ������� ����� �����
        str.erase(0, str.find(" ") + 1);     // ��������� ������� ����� �����
        st[l] = word;
        l++;  // ��������� �������
    }
    st[k - 1] = str; //����� ���������� ����� �����
    for (int i = 0; i < k; i++)   // ���������� ����������
        for (int j = 0; j < k - i - 1; j++)
            if (size(st[j]) < size(st[j + 1])) { // ��������� ������� ���
                el = st[j]; // ���������� �������� �������� ������
                st[j] = st[j + 1]; // ����� �������� ��������
                st[j + 1] = el;    // ����� �������� ��������
            }
    ofstream File1(FileTwo);  // ³������� ����� ��� ������
    for (int i = 0; i < k; i++)  // ����� ������ � ����
        File1 << st[i] << " ";
    File1.close();
    delete[]st;
}

int NumWords(string FileTwo) {
    int k = 0;  // ʳ������ ��� � �����
    ifstream File(FileTwo);  // ³������� ����� ��� �������
    string st;  // ����� �����
    getline(File, st);
    for (int i = 0; i < size(st); i++) // ��������� �������� ������
        if (st[i] == ' ')
            k++;
    File.close();
    return k + 1;
}