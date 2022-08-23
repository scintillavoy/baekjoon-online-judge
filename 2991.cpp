#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int i = 0; i < 3; ++i) {
        int T, cnt = 0;
        cin >> T;
        if ((T - 1) % (A + B) < A) {
            ++cnt;
        }
        if ((T - 1) % (C + D) < C) {
            ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}
