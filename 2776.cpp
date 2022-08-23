#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        unordered_set<int> S;
        S.reserve(N);
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            S.insert(num);
        }
        int M;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            int num;
            cin >> num;
            cout << S.count(num) << '\n';
        }
    }
    return 0;
}
