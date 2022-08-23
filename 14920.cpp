#include <iostream>
using namespace std;

int main() {
    int C, n = 1;
    cin >> C;
    while (C != 1) {
        if (C % 2 == 0) {
            C /= 2;
        } else {
            C = 3*C + 1;
        }
        ++n;
    }
    cout << n;
    return 0;
}
