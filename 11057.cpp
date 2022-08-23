#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int dp[1001][10] = {0};
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < 1001; ++i) {
        for (int j = 0; j < 10; ++j) {
            dp[i][j] = accumulate(dp[i-1], dp[i-1] + j + 1, 0) % 10007;
        }
    }
    int N;
    cin >> N;
    cout << accumulate(dp[N], dp[N] + 10, 0) % 10007;
    return 0;
}
