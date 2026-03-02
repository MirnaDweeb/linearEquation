#include "Equation.h"
#include <sstream>
#include <cstdlib>
#include <cmath>

Equation::Equation() {
    rhs = 0;
}

void Equation::parse(string line) {

    coeff.clear();
    rhs = 0;

    int equalPos = line.find('=');
    string left = line.substr(0, equalPos);
    string right = line.substr(equalPos + 1);

    rhs = atof(right.c_str());

    left += "+"; 

    string term = "";
    float constantSum = 0;

    for (int i = 0; i < left.size(); i++) {

        if (left[i] == '+' || left[i] == '-') {

            if (term != "") {

                int xPos = term.find('x');

                if (xPos != string::npos) {

                    string coefStr = term.substr(0, xPos);
                    string varStr = term.substr(xPos + 1);

                    float coef;
                    if (coefStr == "" || coefStr == "+") coef = 1;
                    else if (coefStr == "-") coef = -1;
                    else coef = atof(coefStr.c_str());

                    int varIndex = atoi(varStr.c_str());

                    coeff[varIndex] += coef;
                }
                else {
                    constantSum += atof(term.c_str());
                }
            }

            term = left[i];
        }
        else {
            term += left[i];
        }
    }

    rhs -= constantSum;
}

void Equation::print() {

    bool first = true;

    for (auto it : coeff) {

        if (fabs(it.second) < 0.00001) continue;

        if (!first && it.second > 0)
            cout << "+";

        if (it.second == 1)
            cout << "x" << it.first;
        else if (it.second == -1)
            cout << "-x" << it.first;
        else
            cout << it.second << "x" << it.first;

        first = false;
    }

    cout << "=" << rhs << endl;
}