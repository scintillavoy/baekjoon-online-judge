#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(N));
  long long half = 0;
  for (auto &row : vec) {
    for (auto &x : row) {
      cin >> x;
      half += x;
    }
  }
  half = half / 2 + half % 2;
  int left = 0, right = 10'000'000;
  while (left <= right) {
    int mid = (left + right) / 2;
    long long count = 0;
    for (const auto &row : vec) {
      for (const auto &x : row) {
        count += min(x, mid);
      }
    }
    if (count < half) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}
