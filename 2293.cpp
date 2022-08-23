#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coin(n), dp(k+1);
    for (auto &x : coin) {
        cin >> x;
    }
    dp[0] = 1;
    for (auto const &x : coin) {
        for (int i = 0; i <= k - x; ++i) {
            dp[i + x] += dp[i];
        }
    }
    cout << dp[k];
    return 0;
}
