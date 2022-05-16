#include "TQuadrangle.h"
#include <iomanip>
#include <iomanip>
double TQuadrangle::countPerim() { // ��������� ���������
	double Perim = 0;
	Coordiantes Side; // ���������� ������� �������
	for (int i = 0; i < 4; i++) {
		Side.x = V[(i + 1)%4].x - V[i].x;
		Side.y = V[(i + 1)%4].y - V[i].y;
		Perim += sqrt(pow(Side.x, 2) + pow(Side.y, 2)); // ������ ������� �������
	}
	return Perim;
}

void TQuadrangle::getAllInfo() { // ���� ���������� ��� ������
	printf("%-13s Perimetr: %-6.2f Area: %-6.2f\n", type.c_str(), perimeter, area);
}

TQuadrangle::TQuadrangle(Coordiantes v[4], string typ) : type(typ) { // �����������
	for (int i = 0; i < 4; i++) V[i] = v[i];
	perimeter = countPerim();
}
