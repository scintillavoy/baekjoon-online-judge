#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;
        cout << M * 2 - N << ' ' << N - M << '\n';
    }
    return 0;
}
