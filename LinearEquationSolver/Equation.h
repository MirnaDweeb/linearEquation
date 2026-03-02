#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Equation {
public:
    map<int, float> coeff;   
    float rhs;               

    Equation();
    void parse(string line);
    void print();
};

#endif