#include <iostream>
#include <limits>
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
    int arr[5];
    for (auto &x : arr) {
        cin >> x;
    }
    int minVal = numeric_limits<int>::max();
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                int val = lcm(lcm(arr[i], arr[j]), arr[k]);
                if (val < minVal) {
                    minVal = val;
                }
            }
        }
    }
    cout << minVal;
    return 0;
}
