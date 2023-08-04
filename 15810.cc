#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  long long left = 1, right = *min_element(vec.cbegin(), vec.cend()) * M;
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long count = 0;
    for (const auto &x : vec) {
      count += mid / x;
    }
    if (count < M) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}
