#include "System.h"
#include <sstream>

int main() {

    int n;
    cin >> n;

    System sys;
    sys.readSystem(n);

    string command;

    while (true) {

        cin >> command;

        if (command == "quit")
            break;

        if (command == "num_vars")
            cout << sys.numVars << endl;

        else if (command == "equation") {
            int i;
            cin >> i;
            sys.printEquation(i);
        }

        else if (command == "column") {
            string var;
            cin >> var;
            int v = atoi(var.substr(1).c_str());
            sys.printColumn(v);
        }

        else if (command == "add") {
            int i, j;
            cin >> i >> j;
            sys.addEq(i, j);
        }

        else if (command == "subtract") {
            int i, j;
            cin >> i >> j;
            sys.subEq(i, j);
        }

        else if (command == "substitute") {
            string var;
            int i, j;
            cin >> var >> i >> j;
            int v = atoi(var.substr(1).c_str());
            sys.substitute(v, i, j);
        }

        else if (command == "D")
        {
            string next;
            getline(cin, next);

            if (next == "")
                sys.printD();
            else {
                stringstream ss(next);
                string var;
                ss >> var;
                int v = atoi(var.substr(1).c_str());
                sys.printDx(v);
            }
        }

        else if (command == "D_value")
            sys.printDvalue();

        else if (command == "solve")
            sys.solve();
    }

    return 0;
}