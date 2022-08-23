#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> vecN(N);
        double avgN = 0, avgM = 0;
        for (auto &x : vecN) {
            cin >> x;
            avgN += x;
        }
        for (int i = 0; i < M; ++i) {
            int x;
            cin >> x;
            avgM += x;
        }
        avgN /= N;
        avgM /= M;
        int cnt = 0;
        for (auto const &x : vecN) {
            if (x < avgN && x > avgM) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
