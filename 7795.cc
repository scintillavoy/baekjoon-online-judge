#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto &x : A) {
      cin >> x;
    }
    for (auto &x : B) {
      cin >> x;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int b = 0, answer = 0;
    for (int i = 0; i < A.size(); ++i) {
      while (b < B.size() && A[i] > B[b]) {
        ++b;
      }
      answer += b;
    }
    cout << answer << '\n';
  }
  return 0;
}
