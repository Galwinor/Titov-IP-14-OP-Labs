#pragma once
#include "TQuadrangle.h"

TQuadrangle* createItem(Coordiantes [4]);
std::vector<TQuadrangle*> input(int);
bool isColiniar(Coordiantes, Coordiantes);
bool isEquel(Coordiantes, Coordiantes);
void output(vector<TQuadrangle*>);
void calculateSum(vector<TQuadrangle*>);