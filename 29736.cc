#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B;
  cin >> A >> B;
  int K, X;
  cin >> K >> X;
  int start = K - X, end = K + X;
  if (end < A || start > B) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << min(end, B) - max(start, A) + 1;
  return 0;
}
