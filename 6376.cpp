#include <iostream>
using namespace std;

int main() {
    cout << "n e\n";
    cout << "- -----------\n";
    cout << "0 1\n";
    cout << "1 2\n";
    cout << "2 2.5\n";
    double e = 2.5;
    int factorial = 2;
    cout.precision(9);
    cout << fixed;
    for (int n = 3; n <= 9; ++n) {
        factorial *= n;
        e += 1 / double(factorial);
        cout << n << ' ' << e << '\n';
    }
    return 0;
}
