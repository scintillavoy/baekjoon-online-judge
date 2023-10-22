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
  memo.push_back(A[0]);
  for (int i = 1; i < N; ++i) {
    if (memo.back() < A[i]) {
      memo.push_back(A[i]);
    } else {
      auto it = lower_bound(memo.begin(), memo.end(), A[i]);
      *it = A[i];
    }
  }
  cout << memo.size();
  return 0;
}
