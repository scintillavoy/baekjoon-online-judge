#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

int main() {
    cout.precision(3);
    cout << fixed;
    int a, b, c;
    for (int i = 1; cin >> a >> b >> c; ++i) {
        if (!a && !b & !c) {
            break;
        }
        cout << "Triangle #" << i << '\n';
        if (c == -1) {
            cout << "c = " << sqrt(a * a + b * b);
        } else {
            if (a >= c || b >= c) {
                cout << "Impossible.";
            } else {
                if (a == -1) {
                    cout << "a = ";
                } else {
                    cout << "b = ";
                    swap(a, b);
                }
                cout << sqrt(c * c - b * b);
            }
        }
        cout << "\n\n";
    }
    return 0;
}
