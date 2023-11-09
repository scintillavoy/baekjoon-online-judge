#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int m;
  cin >> m;
  vector<int> B(m);
  for (int i = 0; i < m; ++i) {
    cin >> B[i];
  }
  vector<int> A2(n);
  A2[0] = A[0];
  for (int i = 1; i < n; ++i) {
    A2[i] = A2[i - 1] + A[i];
  }
  vector<int> B2(m);
  B2[0] = B[0];
  for (int i = 1; i < m; ++i) {
    B2[i] = B2[i - 1] + B[i];
  }
  unordered_map<int, int> A_sum;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int sum = A2[j];
      if (i != 0) {
        sum -= A2[i - 1];
      }
      ++A_sum[sum];
    }
  }
  long long count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      int sum = B2[j];
      if (i != 0) {
        sum -= B2[i - 1];
      }
      if (A_sum.count(T - sum) != 0) {
        count += A_sum[T - sum];
      }
    }
  }
  cout << count;
  return 0;
}
