#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, D;
        cin >> N >> D;
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            int v, f, c;
            cin >> v >> f >> c;
            if (v * f >= D * c) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
