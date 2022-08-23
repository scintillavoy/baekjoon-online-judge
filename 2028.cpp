#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int mod = 1;
        for (int n = N; n > 0; n /= 10) {
            mod *= 10;
        }
        cout << (N * N % mod == N ? "YES" : "NO") << '\n';
    }
    return 0;
}
