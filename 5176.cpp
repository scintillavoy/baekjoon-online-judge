#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int P, M;
        cin >> P >> M;
        vector<bool> vec(M, false);
        int cnt = 0;
        for (int j = 0; j < P; ++j) {
            int seat;
            cin >> seat;
            if (vec[seat - 1]) {
                ++cnt;
            } else {
                vec[seat - 1] = true;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
