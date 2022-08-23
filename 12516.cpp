#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            if (num != j + 1) {
                ++cnt;
            }
        }
        cout << "Case #" << i + 1 << ": " << cnt << ".000000\n";
    }
    return 0;
}
