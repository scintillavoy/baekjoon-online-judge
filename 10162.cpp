#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int A = 0, B = 0, C = 0;
    A = T / 300;
    T %= 300;
    B = T / 60;
    T %= 60;
    C = T / 10;
    T %= 10;
    if (T != 0) {
        cout << "-1";
    } else {
        cout << A << ' ' << B << ' ' << C;
    }
    return 0;
}
