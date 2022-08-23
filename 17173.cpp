#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> check(N+1, false);
    for (int i = 0; i < M; ++i) {
        int K;
        cin >> K;
        for (int j = K; j <= N; j += K) {
            check[j] = true;
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (check[i]) {
            sum += i;
        }
    }
    cout << sum << '\n';
    return 0;
}
