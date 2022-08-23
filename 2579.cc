#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> points(N);
  for (auto &x : points) {
    cin >> x;
  }

  vector<int> dp(N, -1);
  dp[0] = points[0];
  dp[1] = points[0] + points[1];
  dp[2] = max(points[0], points[1]) + points[2];

  for (int i = 3; i < dp.size(); ++i) {
    dp[i] = max(dp[i - 3] + points[i - 1], dp[i - 2]) + points[i];
  }

  cout << dp.back();
  return 0;
}
