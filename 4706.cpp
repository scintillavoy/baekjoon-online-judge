#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double ta, tb;
    cout.precision(3);
    cout << fixed;
    while (cin >> ta >> tb) {
        if (ta == 0 && tb == 0) {
            break;
        }
        cout << sqrt(1 - (tb / ta) * (tb / ta)) << '\n';
    }
    return 0;
}
