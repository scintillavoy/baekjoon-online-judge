#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> max_dp(3), min_dp(3);
  while (N--) {
    int a, b, c;
    cin >> a >> b >> c;
    max_dp = {
        a + max(max_dp[0], max_dp[1]),
        b + max({max_dp[0], max_dp[1], max_dp[2]}),
        c + max(max_dp[1], max_dp[2]),
    };
    min_dp = {
        a + min(min_dp[0], min_dp[1]),
        b + min({min_dp[0], min_dp[1], min_dp[2]}),
        c + min(min_dp[1], min_dp[2]),
    };
  }
  cout << *max_element(max_dp.cbegin(), max_dp.cend()) << ' '
       << *min_element(min_dp.cbegin(), min_dp.cend());
  return 0;
}
