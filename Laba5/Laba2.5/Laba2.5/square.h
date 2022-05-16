#pragma once
#include "rectangle.h"
class square: public rectangle
{
public:
	square(Coordiantes V[4]) : rectangle(V, "Square") { area = countArea(); }
	double countArea();
};

