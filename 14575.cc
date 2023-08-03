#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> vec(N);
  int left_sum = 0, right_sum = 0;
  for (auto &x : vec) {
    cin >> x.first >> x.second;
    left_sum += x.first;
    right_sum += x.second;
  }
  if (left_sum > T || right_sum < T) {
    cout << -1;
    return 0;
  }
  int left = max_element(vec.cbegin(), vec.cend(),
                         [](const pair<int, int> &a, const pair<int, int> &b) {
                           return a.first < b.first;
                         })
                 ->first;
  int right = max_element(vec.cbegin(), vec.cend(),
                          [](const pair<int, int> &a, const pair<int, int> &b) {
                            return a.second < b.second;
                          })
                  ->second;
  while (left <= right) {
    int mid = (left + right) / 2;
    int sum = 0;
    for (const auto &x : vec) {
      sum += min(x.second, mid);
    }
    if (sum < T) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}
