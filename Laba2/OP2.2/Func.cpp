#pragma warning(disable:4996)
#define Sal a.SaleRelease
#define Rel a.Release
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "OP2.2.h"
using namespace std;

void input(char cont) {
	char k; // ������ ������, �� ��������� ����� ����������� �� ������������ �����
	AutoBase a; // �����, �� ������ ���������� ��� ������
	string Read; // ����� ��� ������� � ������
	ofstream In; 
	if (cont == '+') { In.open("AutoBase.txt", ios::binary | ios::app); cin.ignore(); }// ³������� ����� ��� ��������
	else In.open("AutoBase.txt", ios::binary); // ³������� ����� ��� ������
	do {
		cout << "Enter name of car: "; getline(cin, Read); // ��'� ������
		strcpy(a.Name, data(Read));
		cout << "Enter Release Date with a point '10.10.2010': "; getline(cin, Read); // ���� ������������
		a = Divide(a, Read, 0); // ��������� ���� � ������ string �� ���� ������� int
		cout << "Enter Sale Release Date with a point '10.10.2010': "; getline(cin, Read); // ���� �������
		a = Divide(a, Read, 1); // ��������� ���� � ������ string �� ���� ������� int
		cout << "\nEnter '+' in case you want to contnue: "; cin >> k; // �� ���� ���������� ������������
		In.write((char*)&a, sizeof(AutoBase)); // ����� � ���� ����� ��� ������
		cin.ignore();
	} while (k == '+');
	In.close();
}

AutoBase Divide(AutoBase a, string Read, bool b) {
	int pos1 = Read.find('.'); // ������� ����� ������
	int pos2 = Read.rfind('.'); // ������� ����� ������
	if (!b) {
		Rel.day = stoi(Read.substr(0, pos1)); // ����� ��� � �����
		Rel.mounth = stoi(Read.substr(pos1 + 1, pos2)); // ����� ����� � �����
		Rel.year = stoi(Read.substr(pos2 + 1)); // ����� ���� � �����
	}
	else {
		Sal.day = stoi(Read.substr(0, pos1)); // ����� ��� � �����
		Sal.mounth = stoi(Read.substr(pos1 + 1, pos2)); // ����� ����� � �����
		Sal.year = stoi(Read.substr(pos2 + 1)); // ����� ���� � �����
	}
	return a;
}

void CreateList() {
	string date = datta(); // ������� ����
	ifstream Out("Autobase.txt", ios::binary); // ³������� ����� ��� �������
	ofstream In("OneMounth.txt", ios::binary); // ³������� ����� ��� ������
	AutoBase a; // �����, �� ������ ���������� ��� ������
	bool flag = true; // �������� �����, �� ���������� ������
	int day = stoi(date.substr(0, date.find('.'))); // �������� ����
	int mounth = stoi(date.substr(date.find('.') + 1, date.rfind('.'))); // �������� �����
	int year = stoi(date.substr(date.rfind('.') + 1)); // �������� ��
	int d1 = day + mounth * 31 + year * 365; // ������� ���� � ����
	int d2; // ���� ������� � ����
	while (Out.read((char*)&a, sizeof(AutoBase))) { // ������� � �����
		d2 = Sal.day + Sal.mounth * 31 + Sal.year * 365;
		if (d2 + 31 >= d1) { // ������, �� ���� ������ � ������� �����
			In.write((char*)&a, sizeof(AutoBase)); // ����� � ����
			flag = false;
		}
	}
	In.close();
	Out.close();
	cout << "\nCars on Sale in last mounth: \n";
	if (flag) cout << "No cars.\n"; // ���� ����� ����� ����
	else output("OneMounth.txt");// ���� ����� �����
}

string datta() { // ������� ����
	const time_t tm = time(nullptr);
	char buf[64];
	strftime(buf, sizeof(buf), "%d.%m.%Y", localtime(&tm));
	string date = buf; 
	return date;
}

void output(string name) {
	ifstream Out(name, ios::binary); // ³������� ����� ��� �������
	AutoBase a; // �����, �� ������ ���������� ��� ������
	while (Out.read((char*)&a, sizeof(AutoBase))) // ������� � �����
		printf("Name: %-15s Release date: %02i.%02i.%-9i Sale Release date: %02i.%.02i.%-9i\n",
			a.Name, Rel.day, Rel.mounth, Rel.year, Sal.day, Sal.mounth, Sal.year);
	Out.close();
}

void UseedAuto() {
	cout << "\nSaled after >1 year after Release: \n";
	ifstream Out("Autobase.txt", ios::binary); // ³������� ����� ��� �������
	AutoBase a; // �����, �� ������ ��������� ��� ������
	bool flag = true; // �������� �����, �� ���������� ������
	int d1, d2; // ���� � ����
	while (Out.read((char*)&a, sizeof(AutoBase))) {// ������� � �����
		d1 = Sal.day + Sal.mounth * 31 + Sal.year * 365; // ���� ������������
		d2 = Rel.day + Rel.mounth * 31 + Rel.year * 365; // ���� �������
		if (d2 + 365 < d1) { // ������, �� ���� ������ ����� �� ����� �� ���� ���������
			printf("Name: %-15s Release date: %02i.%02i.%-9i Sale Release date: %02i.%.02i.%-9i\n",
				a.Name, Rel.day, Rel.mounth, Rel.year, Sal.day, Sal.mounth, Sal.year);
			flag = false;
		}
	}
	if (flag) cout << "No cars.\n"; // ���� ����� ����� ����
	Out.close();
}