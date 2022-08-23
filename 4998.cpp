#include <iostream>
using namespace std;

int main() {
    double N, B, M;
    while (cin >> N >> B >> M) {
        int cnt = 0;
        while (N < M) {
            N *= 1 + B / 100;
            ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}
