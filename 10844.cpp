#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int dp[101][10] = {0};
    for (int i = 1; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < 101; ++i) {
        dp[i][0] = dp[i-1][1];
        for (int j = 1; j < 9; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][9] = dp[i-1][8];
    }
    int N;
    cin >> N;
    cout << accumulate(dp[N], dp[N] + 10, 0, [](const int &a, const int &b) {
        return (a + b) % 1000000000;
    });
    return 0;
}
