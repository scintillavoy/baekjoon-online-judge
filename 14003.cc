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
  vector<int> memo;
  vector<int> length(N);
  memo.push_back(A[0]);
  length[0] = 1;
  for (int i = 1; i < N; ++i) {
    if (memo.back() < A[i]) {
      memo.push_back(A[i]);
      length[i] = memo.size();
    } else {
      auto it = lower_bound(memo.begin(), memo.end(), A[i]);
      *it = A[i];
      length[i] = it - memo.begin() + 1;
    }
  }
  cout << memo.size() << '\n';
  int curr_length = memo.size();
  vector<int> lis;
  for (int i = N - 1; i >= 0 && curr_length > 0; --i) {
    if (length[i] == curr_length) {
      lis.push_back(A[i]);
      --curr_length;
    }
  }
  for (auto it = lis.crbegin(); it != lis.crend(); ++it) {
    cout << *it << ' ';
  }
  return 0;
}
