#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            cnt += i * i;
        }
        cout << cnt << '\n';
    }
    return 0;
}
