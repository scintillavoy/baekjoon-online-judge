#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int d;
        cin >> d;
        cout << int(floor((-1 + sqrt(1 + 4*d)) / 2)) << '\n';
    }
    return 0;
}
