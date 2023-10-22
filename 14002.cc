#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> dp(N, 1);
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int max_length = *max_element(dp.cbegin(), dp.cend());
  cout << max_length << '\n';
  vector<int> lis;
  for (int i = N - 1; i >= 0 && max_length > 0; --i) {
    if (dp[i] == max_length) {
      lis.push_back(A[i]);
      --max_length;
    }
  }
  for (auto it = lis.crbegin(); it != lis.crend(); ++it) {
    cout << *it << ' ';
  }
  return 0;
}
