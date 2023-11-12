#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n), B(n), C(n), D(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++m[A[i] + B[j]];
    }
  }
  long long count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (m.count(-C[i] - D[j]) != 0) {
        count += m[-C[i] - D[j]];
      }
    }
  }
  cout << count;
  return 0;
}
