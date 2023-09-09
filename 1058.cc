#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> distance_(N,
                                vector<int>(N, numeric_limits<int>::max() / 2));
  for (int i = 0; i < N; ++i) {
    distance_[i][i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      if (c == 'Y') {
        distance_[i][j] = 1;
      }
    }
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (distance_[i][j] > distance_[i][k] + distance_[k][j]) {
          distance_[i][j] = distance_[i][k] + distance_[k][j];
        }
      }
    }
  }
  int max_count = 0;
  for (int i = 0; i < N; ++i) {
    int count = 0;
    for (int j = 0; j < N; ++j) {
      if (i == j) {
        continue;
      }
      if (distance_[i][j] <= 2) {
        ++count;
      }
    }
    max_count = max(max_count, count);
  }
  cout << max_count;
  return 0;
}
