#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int p[3], c[3];
    cin >> p[0] >> p[1] >> p[2];
    cin >> c[0] >> c[1] >> c[2];
    sort(p, p+3, greater<int>());
    sort(c+1, c+3, greater<int>());
    double saving[2];
    saving[0] = (double)(p[0] + p[1] + p[2]) * c[0] / 100;
    saving[1] = (double)(p[0] * c[1] + p[1] * c[2]) / 100;
    cout << fixed;
    cout.precision(2);
    if (saving[0] > saving[1]) {
        cout << "one " << saving[0];
    } else {
        cout << "two " << saving[1];
    }
    cout << '\n';
    return 0;
}
