#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        int divisor = 2, cnt = 0;
        while (divisor <= N) {
            if (N % divisor == 0) {
                N /= divisor;
                ++cnt;
            } else {
                if (cnt > 0) {
                    cout << divisor << ' ' << cnt << '\n';
                }
                cnt = 0;
                ++divisor;
            }
        }
        if (cnt > 0) {
            cout << divisor << ' ' << cnt << '\n';
        }
    }
    return 0;
}
