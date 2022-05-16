#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Coordiantes { // ��������� ���������
	double x, y;
};

class TQuadrangle
{
	double countPerim(); // ��������� ���������
protected:
	Coordiantes V[4]; // ���������� ������
	double perimeter; // ��������
	double area; // �����
	const string type; // ��� ������
	virtual double countArea() = 0; // ��������� �����
public:
	TQuadrangle(Coordiantes [4], string); // �����������
	void getAllInfo(); // ���� ���������� ��� ������
	string getType() { return type; } // ����� ����
	double getPer() { return perimeter; } // ����� ���������
	double getArea() { return area; } // ����� �����
};