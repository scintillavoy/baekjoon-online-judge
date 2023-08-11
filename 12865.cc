#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> dp(K + 1);
  for (int i = 1; i <= N; ++i) {
    int W, V;
    cin >> W >> V;
    for (int j = K; j >= W; --j) {
      dp[j] = max(dp[j], dp[j - W] + V);
    }
  }
  cout << dp[K];
  return 0;
}
