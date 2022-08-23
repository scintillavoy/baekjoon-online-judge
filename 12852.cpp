#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1), sol(N + 1);
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i-1] + 1;
        sol[i] = i - 1;
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            sol[i] = i / 2;
            
        }
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            sol[i] = i / 3;
        }
    }
    cout << dp[N] << '\n';
    for (int i = N; i >= 1; i = sol[i]) {
        cout << i << ' ';
    }
    return 0;
}
