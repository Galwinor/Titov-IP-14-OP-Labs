#include "parallelogram.h"

double parallelogram::countArea() { // ��������� �����
	double Side1, Side2, sina;
	Side1 = sqrt(pow(V[1].x - V[0].x, 2) + pow(V[1].y - V[0].y, 2)); // ����� �������
	Side2 = sqrt(pow(V[2].x - V[1].x, 2) + pow(V[2].y - V[1].y, 2)); // ����� �������
	sina = sin(acos(abs(((V[0].x - V[1].x)*(V[2].x - V[1].x) + (V[0].y - V[1].y)*(V[2].y - V[1].y))/(Side1*Side2)))); // ����� ���� �� ���������
	return Side1 * Side2 * sina;
}