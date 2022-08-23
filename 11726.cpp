#include <iostream>
using namespace std;

int main() {
    int dp[1001] = {0, 1, 2, };
    for (int i = 3; i < 1001; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}
