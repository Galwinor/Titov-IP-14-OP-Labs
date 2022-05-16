#pragma once
#include "TQuadrangle.h"

class parallelogram: public TQuadrangle
{
public:
	parallelogram(Coordiantes V[4]) : TQuadrangle(V, "Parallelogram") { area = countArea();} 
	double countArea();
};

