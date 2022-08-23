#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;
        int cnt = 0;
        for (int j = N; j <= M; ++j) {
            int num = j;
            do {
                if (num % 10 == 0) {
                    ++cnt;
                }
                num /= 10;
            } while (num > 0);
        }
        cout << cnt << '\n';
    }
    return 0;
}
