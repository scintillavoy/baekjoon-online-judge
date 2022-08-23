#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
    return 0;
}
