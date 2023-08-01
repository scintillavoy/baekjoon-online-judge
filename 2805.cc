#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  int left = 0, right = *max_element(vec.cbegin(), vec.cend());
  while (left <= right) {
    int mid = (left + right) / 2;
    long long sum = 0;
    for (const auto &x : vec) {
      sum += max(0, x - mid);
    }
    if (sum >= M) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left - 1;
  return 0;
}
