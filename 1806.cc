#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  int sum = 0;
  int length = 0;
  int left = 0;
  int min_length = numeric_limits<int>::max();
  for (int i = 0; i < N; ++i) {
    sum += vec[i];
    ++length;
    while (sum >= S) {
      min_length = min(min_length, length);
      sum -= vec[left];
      --length;
      ++left;
    }
  }
  cout << (min_length == numeric_limits<int>::max() ? 0 : min_length);
  return 0;
}
