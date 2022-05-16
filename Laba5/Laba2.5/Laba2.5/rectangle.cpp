#include "rectangle.h"

double rectangle::countArea() { // Обрахунок площі прямокутника
	double Side1, Side2;
	Side1 = sqrt(pow(V[1].x - V[0].x, 2) + pow(V[1].y - V[0].y, 2)); // Довжина першої сторони
	Side2 = sqrt(pow(V[2].x - V[1].x, 2) + pow(V[2].y - V[1].y, 2)); // Довжина другої сторони
	return Side1 * Side2;
}
