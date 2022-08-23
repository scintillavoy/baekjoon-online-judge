#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int N, firstRad;
    cin >> N >> firstRad;
    for (int i = 1; i < N; ++i) {
        int rad;
        cin >> rad;
        cout << firstRad / gcd(firstRad, rad) << '/';
        cout << rad / gcd(firstRad, rad) << '\n';
    }
    return 0;
}
