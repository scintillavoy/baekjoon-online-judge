#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int H, P;
    cout.precision(2);
    cout << fixed;
    while (cin >> H >> P) {
        cout << floor((double) H / P * pow(10, 2) + 0.5) / pow(10, 2) << '\n';
    }
    return 0;
}
