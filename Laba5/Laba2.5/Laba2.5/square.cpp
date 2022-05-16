#include "square.h"

double square::countArea() { // Обрахунок площі
	double Side;
	Side = sqrt(pow(V[1].x - V[0].x, 2) + pow(V[1].y - V[0].y, 2)); // Довжина однієї сторони
	return pow(Side, 2);
}
