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
  sort(vec.begin(), vec.end());
  long long count = 0;
  for (int i = 0; i < N - 2; ++i) {
    int left = i + 1, right = N - 1;
    while (left < right) {
      int sum = vec[i] + vec[left] + vec[right];
      if (sum == 0) {
        if (vec[left] == vec[right]) {
          count += (right - left + 1) * (right - left) / 2;
          break;
        } else {
          int left_count = 1, right_count = 1;
          while (left + 1 < right && vec[left] == vec[left + 1]) {
            ++left_count;
            ++left;
          }
          while (left < right - 1 && vec[right - 1] == vec[right]) {
            ++right_count;
            --right;
          }
          count += left_count * right_count;
        }
      }
      if (sum < 0) {
        ++left;
      } else {
        --right;
      }
    }
  }
  cout << count;
  return 0;
}
