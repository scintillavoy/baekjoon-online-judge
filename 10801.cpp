#include <iostream>
using namespace std;

int main() {
    int arrA[10], arrB[10];
    for (auto &x : arrA) {
        cin >> x;
    }
    for (auto &x : arrB) {
        cin >> x;
    }
    int cntA = 0, cntB = 0;
    for (int i = 0; i < 10; ++i) {
        if (arrA[i] > arrB[i]) {
            ++cntA;
        } else if (arrA[i] < arrB[i]) {
            ++cntB;
        }
    }
    if (cntA > cntB) {
        cout << 'A';
    } else if (cntA < cntB) {
        cout << 'B';
    } else {
        cout << 'D';
    }
}