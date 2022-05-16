#pragma once
#include "TQuadrangle.h"
using namespace std;

class rectangle: public TQuadrangle
{
public:
	rectangle(Coordiantes V[4], string type = "Rectangle") : TQuadrangle(V, type) { area = countArea(); }
	double countArea();
};

