#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(N);
  int right = 0;
  for (auto &x : vec) {
    cin >> x;
    right += x;
  }
  int left = *max_element(vec.cbegin(), vec.cend());
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = 1;
    int remaining = mid;
    for (const auto &x : vec) {
      if (remaining < x) {
        ++count;
        remaining = mid;
      }
      remaining -= x;
    }
    if (count > M) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}
