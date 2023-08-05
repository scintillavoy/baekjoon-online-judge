#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  vector<int> dp(N, 1);
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (vec[j] > vec[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.cbegin(), dp.cend());
  return 0;
}
