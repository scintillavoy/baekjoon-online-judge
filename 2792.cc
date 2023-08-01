#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(M);
  for (auto &x : vec) {
    cin >> x;
  }
  int left = 1, right = *max_element(vec.cbegin(), vec.cend());
  while (left <= right) {
    int mid = (left + right) / 2;
    long long count = 0;
    for (const auto &x : vec) {
      count += x / mid;
      if (x % mid != 0) {
        ++count;
      }
    }
    if (count > N) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}
