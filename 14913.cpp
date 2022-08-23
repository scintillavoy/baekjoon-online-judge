#include <iostream>
using namespace std;

int main() {
    int a, d, k;
    cin >> a >> d >> k;
    int cnt;
    if (d > 0) {
        for (cnt = 1; k > a; ++cnt) {
            a += d;
        }
    } else {
        for (cnt = 1; k < a; ++cnt) {
            a += d;
        }
    }
    if (k == a) {
        cout << cnt;
    } else {
        cout << 'X';
    }
    return 0;
}
