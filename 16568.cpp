#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int N, a, b;
    cin >> N >> a >> b;
    ++a;
    ++b;
    vector<int> dp(N+1, numeric_limits<int>::max()-1);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        dp[i+1] = min(dp[i+1], dp[i]+1);
        if (i+a <= N) {
            dp[i+a] = min(dp[i+a], dp[i]+1);
        }
        if (i+b <= N) {
            dp[i+b] = min(dp[i+b], dp[i]+1);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
