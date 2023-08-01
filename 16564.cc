#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> X(N);
  for (auto &x : X) {
    cin >> x;
  }
  long long left = *min_element(X.cbegin(), X.cend()), right = left + K;
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long diff = 0;
    for (const auto &x : X) {
      diff += max((long long)0, mid - x);
    }
    if (diff <= K) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left - 1;
  return 0;
}
