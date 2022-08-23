#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int dp[1001] = {0};
    for (int i = 2; i <= 1000; ++i) {
        dp[i] = dp[i-1];
        for (int j = 1; j <= i - 1; ++j) {
            if (gcd(i, j) == 1) {
                ++dp[i];
            }
        }
    }
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        cout << dp[N] * 2 + 3 << '\n';
    }
    return 0;
}
