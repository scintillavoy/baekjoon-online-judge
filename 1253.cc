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
  sort(A.begin(), A.end());
  int count = 0;
  for (int i = 0; i < N; ++i) {
    int left = 0, right = N - 1;
    if (left == i) {
      ++left;
    }
    if (right == i) {
      --right;
    }
    while (left < right) {
      if (A[left] + A[right] < A[i]) {
        ++left;
        if (left == i) {
          ++left;
        }
      } else if (A[left] + A[right] > A[i]) {
        --right;
        if (right == i) {
          --right;
        }
      } else {
        ++count;
        break;
      }
    }
  }
  cout << count;
  return 0;
}
