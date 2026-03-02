#include "System.h"
#include <iomanip>

void System::readSystem(int n) {

    equations.resize(n);
    numVars = 0;

    string line;
    getline(cin, line); 

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        equations[i].parse(line);

        for (auto p : equations[i].coeff)
            if (p.first > numVars)
                numVars = p.first;
    }
}

void System::printEquation(int i) {
    equations[i - 1].print();
}

void System::printColumn(int var) {
    for (int i = 0; i < equations.size(); i++)
        cout << equations[i].coeff[var] << endl;
}

void System::addEq(int i, int j) {

    Equation result;

    for (int v = 1; v <= numVars; v++)
        result.coeff[v] = equations[i - 1].coeff[v] + equations[j - 1].coeff[v];

    result.rhs = equations[i - 1].rhs + equations[j - 1].rhs;

    result.print();
}

void System::subEq(int i, int j) {

    Equation result;

    for (int v = 1; v <= numVars; v++)
        result.coeff[v] = equations[i - 1].coeff[v] - equations[j - 1].coeff[v];

    result.rhs = equations[i - 1].rhs - equations[j - 1].rhs;

    result.print();
}

void System::substitute(int var, int eq1, int eq2) {

    Equation e1 = equations[eq1 - 1];
    Equation e2 = equations[eq2 - 1];

    float coef = e1.coeff[var];

    if (coef == 0) {
        e1.print();
        return;
    }

    for (int v = 1; v <= numVars; v++)
        e1.coeff[v] -= coef * e2.coeff[v];

    e1.rhs -= coef * e2.rhs;
    e1.coeff[var] = 0;

    e1.print();
}

float System::determinant(vector<vector<float>> m) {

    int n = m.size();
    if (n == 1) return m[0][0];

    float det = 0;

    for (int p = 0; p < n; p++) {

        vector<vector<float>> sub(n - 1, vector<float>(n - 1));

        for (int i = 1; i < n; i++) {
            int colIndex = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                sub[i - 1][colIndex++] = m[i][j];
            }
        }

        det += (p % 2 == 0 ? 1 : -1) * m[0][p] * determinant(sub);
    }

    return det;
}

void System::printD() {

    for (int i = 0; i < equations.size(); i++) {
        for (int v = 1; v <= numVars; v++)
            cout << equations[i].coeff[v] << " ";
        cout << endl;
    }
}

void System::printDx(int var) {

    for (int i = 0; i < equations.size(); i++) {
        for (int v = 1; v <= numVars; v++) {
            if (v == var)
                cout << equations[i].rhs << " ";
            else
                cout << equations[i].coeff[v] << " ";
        }
        cout << endl;
    }
}

void System::printDvalue() {

    vector<vector<float>> m(equations.size(), vector<float>(numVars));

    for (int i = 0; i < equations.size(); i++)
        for (int j = 1; j <= numVars; j++)
            m[i][j - 1] = equations[i].coeff[j];

    cout << determinant(m) << endl;
}

void System::solve() {

    vector<vector<float>> m(equations.size(), vector<float>(numVars));

    for (int i = 0; i < equations.size(); i++)
        for (int j = 1; j <= numVars; j++)
            m[i][j - 1] = equations[i].coeff[j];

    float D = determinant(m);

    if (fabs(D) < 0.00001) {
        cout << "No Solution" << endl;
        return;
    }

    for (int var = 1; var <= numVars; var++) {

        vector<vector<float>> temp = m;

        for (int i = 0; i < equations.size(); i++)
            temp[i][var - 1] = equations[i].rhs;

        float Dx = determinant(temp);

        cout << "x" << var << "=" << Dx / D << endl;
    }
}