#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, N;
  cin >> M >> N;
  vector<int> L(N);
  for (auto &x : L) {
    cin >> x;
  }
  int left = 1, right = *max_element(L.cbegin(), L.cend());
  while (left <= right) {
    int mid = (left + right) / 2;
    long long count = 0;
    for (const auto &x : L) {
      count += x / mid;
    }
    if (count >= M) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left - 1;
  return 0;
}
