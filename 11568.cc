#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
  }
  vector<int> dp(N, 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (vec[j] < vec[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.cbegin(), dp.cend());
  return 0;
}
