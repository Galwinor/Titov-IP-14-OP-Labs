#pragma warning(disable:4996)
#include <string>
#include "OP2.3.h"
using namespace std;

Date Divide(string data) {
	Date dat; // ��������� � ��� ���������� ����
	dat.day = stoi(data.substr(0, data.find('.'))); // ����
	dat.mounth = stoi(data.substr(data.find('.') + 1, data.rfind('.'))); // ̳����
	dat.year = stoi(data.substr(data.rfind('.') + 1)); // г�
	return dat;
}

void output(vector<Product> tovar) {
	cout << "\nList of Products: \n";
	for (int i = 0; i < tovar.size(); i++)
		tovar[i].display(); // ���� ���������� ��� �������
}

void Out_Of_Date(vector<Product> tovar) {
	cout << "\nOut of Date products: \n";
	string date = datta(); // ������� ����
	int d1, d2; // ʳ������ ��� � �����
	bool flag = true; // �� � ��������� ������
	int day = stoi(date.substr(0, date.find('.'))); // �������� ����
	int mounth = stoi(date.substr(date.find('.') + 1, date.rfind('.'))); // �������� �����
	int year = stoi(date.substr(date.rfind('.') + 1)); // �������� ��
	d1 = day + mounth * 31 + year * 365; // ʳ������ ��� � ���
	for (int i = 0; i < tovar.size(); i++) {
		d2 = tovar[i].OutDate(); // ʳ������ ��� � ���
		if (d2 < d1) { // ���� ����� �����������
			tovar[i].display(); 
			flag = false;
		}
	}
	if (flag) cout << "No products.";
}

string datta() { // ������� ����
	const time_t tm = time(nullptr);
	char buf[64];
	strftime(buf, sizeof(buf), "%d.%m.%Y", localtime(&tm));
	string date = buf;
	return date;
}

vector<Product> input() {
	bool flag = true; // �� ������� ������ ����������
	string name, // ����� ��������
		date1, date2, // ���� ������������� � ����������
		fl; // �� ���� ���������� ������������
	vector <Product> Prod; // ����� ��� ��������� ���������� ��� ��'����
	Date RelDate, FinDate; // ���� ������������� � ����������
	do {
		cout << "Enter Name: "; cin >> name;
		cout << "Enter Release Date with . like '10.10.2010': "; cin >> date1;
		RelDate = Divide(date1); // �������� ���, ����� � ����
		cout << "Enter Shelf Life Date with . like '10.10.2010': "; cin >> date2;
		FinDate = Divide(date2); // �������� ���, ����� � ����
		Product tovar(name, RelDate, FinDate); // ��������� ��'���� ������
		Prod.push_back(tovar); // ����� ��'���� � ������
		cout << "\nIf you want to continue, write '+': "; cin >> fl;// �� ���� ���������� ������������
		if (fl != "+") flag = false;
	} while (flag);
	return Prod;
}