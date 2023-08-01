#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  int M;
  cin >> M;
  int left = 1, right = *max_element(vec.cbegin(), vec.cend());
  while (left <= right) {
    int mid = (left + right) / 2;
    int sum = 0;
    for (const auto &x : vec) {
      sum += min(x, mid);
    }
    if (sum <= M) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left - 1;
  return 0;
}
