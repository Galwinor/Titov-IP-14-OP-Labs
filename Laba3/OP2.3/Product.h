#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Date { // ����
	int day;
	int mounth;
	int year;
};

class Product { // �������
	string name; // ����� ��������
	Date Release; // ���� ������������
	Date FinishD; // ���� ��������� ����� ����������
public:
	Product(string Name, Date Rel, Date Fin) { name = Name; Release = Rel; FinishD = Fin; } 
	void display(); // ���� ���������� ��� �������
	int OutDate(); // ������� ���� ��������� ����� ����������
};