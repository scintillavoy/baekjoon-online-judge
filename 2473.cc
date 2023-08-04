#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  sort(vec.begin(), vec.end());
  vector<int> answer{0, 1, N - 1};
  long long min_abs = abs(vec[0] + vec[1] + vec[N - 1]);
  for (int i = 0; i < N - 2; ++i) {
    int left = i + 1, right = N - 1;
    while (left < right) {
      long long sum = vec[i] + vec[left] + vec[right];
      if (abs(sum) < min_abs) {
        min_abs = abs(sum);
        answer = {i, left, right};
      }
      if (sum <= 0) {
        ++left;
      } else {
        --right;
      }
    }
  }
  for (const auto &x : answer) {
    cout << vec[x] << ' ';
  }
  return 0;
}
