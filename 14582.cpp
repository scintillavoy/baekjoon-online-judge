#include <iostream>
using namespace std;

int main() {
    int arrA[9], arrB[9];
    for (auto &x : arrA) {
        cin >> x;
    }
    for (auto &x : arrB) {
        cin >> x;
    }
    int sumA = arrA[0], sumB = 0;
    bool winA;
    for (int i = 1; i < 9; ++i) {
        if (sumA > sumB) {
            winA = true;
            break;
        }
        sumB += arrB[i-1];
        sumA += arrA[i];
    }
    winA = sumA > sumB;
    cout << (winA ? "Yes" : "No");
    return 0;
}
