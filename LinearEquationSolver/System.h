#ifndef SYSTEM_H
#define SYSTEM_H

#include "Equation.h"
#include <vector>

class System {
public:
    vector<Equation> equations;
    int numVars;

    void readSystem(int n);
    void printEquation(int i);
    void printColumn(int var);
    void addEq(int i, int j);
    void subEq(int i, int j);
    void substitute(int var, int eq1, int eq2);
    void printD();
    void printDx(int var);
    float determinant(vector<vector<float>> m);
    void printDvalue();
    void solve();
};

#endif