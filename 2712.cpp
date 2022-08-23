#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        double value;
        string unit;
        cin >> value >> unit;
        cout.precision(4);
        cout << fixed << showpoint;
        if (unit == "kg") {
            value *= 2.2046;
            value = floor(value * pow(10, 4) + 0.5) / pow(10, 4);
            cout << value << " lb\n";
        } else if (unit == "lb") {
            value *= 0.4536;
            value = floor(value * pow(10, 4) + 0.5) / pow(10, 4);
            cout << value << " kg\n";
        } else if (unit == "l") {
            value *= 0.2642;
            value = floor(value * pow(10, 4) + 0.5) / pow(10, 4);
            cout << value << " g\n";
        } else if (unit == "g") {
            value *= 3.7854;
            value = floor(value * pow(10, 4) + 0.5) / pow(10, 4);
            cout << value << " l\n";
        }
    }
    return 0;
}
