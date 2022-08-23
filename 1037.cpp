#include <iostream>
using namespace std;

int main() {
    int num, minA = 1000001, maxA = 1;
    cin >> num;
    while (num--) {
        int A;
        cin >> A;
        if (minA > A) {
            minA = A;
        }
        if (maxA < A) {
            maxA = A;
        }
    }
    cout << minA * maxA;
    return 0;
}
