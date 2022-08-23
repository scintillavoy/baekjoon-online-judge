#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> price(N), dp(N);
    for (auto &x : price) {
        cin >> x;
    }
    dp[0] = price[0];
    for (int i = 1; i < N; ++i) {
        dp[i] = price[i];
        for (int j = 0; j < i; ++j) {
            if (dp[i] < dp[j] + price[i-j-1]) {
                dp[i] = dp[j] + price[i-j-1];
            }
        }
    }
    cout << dp.back();
    return 0;
}
