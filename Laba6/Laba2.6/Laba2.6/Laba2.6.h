#pragma once
#include <iostream>
#include "MyTree.h"
#include <vector>
using namespace std;

vector<string> rebuiltForm(string); 
MyTree* formTree(vector<string>);
void outputTree(const string&, MyTree*, bool);
void changeTree(MyTree*);
void cnangeTree2(MyTree* tree);