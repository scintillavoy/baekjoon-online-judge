#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> numbers{1};
  for (int i = 2; numbers.back() <= N; ++i) {
    numbers.push_back(numbers.back() + i * (i + 1) / 2);
  }
  vector<int> dp(N + 1, numeric_limits<int>::max());
  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < numbers.size(); ++j) {
      if (i - numbers[j] < 0) {
        break;
      }
      dp[i] = min(dp[i], dp[i - numbers[j]] + 1);
    }
  }
  cout << dp[N];
  return 0;
}
