#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, X;
  cin >> N >> X;
  int prev;
  cin >> prev;
  int min_sum = numeric_limits<int>::max();
  for (int i = 1; i < N; ++i) {
    int curr;
    cin >> curr;
    min_sum = min(min_sum, prev + curr);
    prev = curr;
  }
  cout << min_sum * X;
  return 0;
}
