#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;
    int A = 1, B = 0;
    for (int i = 0; i < K; ++i) {
        B += A;
        A = B - A;
    }
    cout << A << ' ' << B;
    return 0;
}
