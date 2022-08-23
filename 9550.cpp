#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, K;
        cin >> N >> K;
        vector<int> vec(N);
        for (int j = 0; j < N; ++j) {
            cin >> vec[j];
        }
        int cnt = 0;
        for (auto const &x : vec) {
            cnt += x / K;
        }
        cout << cnt << '\n';
    }
    return 0;
}
