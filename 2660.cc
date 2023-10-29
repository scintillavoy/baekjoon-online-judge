#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> distance_(
      N + 1, vector<int>(N + 1, numeric_limits<int>::max() / 2));
  for (int i = 1; i <= N; ++i) {
    distance_[i][i] = 0;
  }
  while (true) {
    int from, to;
    cin >> from >> to;
    if (from == -1 && to == -1) {
      break;
    }
    distance_[from][to] = 1;
    distance_[to][from] = 1;
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (distance_[i][j] > distance_[i][k] + distance_[k][j]) {
          distance_[i][j] = distance_[i][k] + distance_[k][j];
        }
      }
    }
  }
  int min_score = numeric_limits<int>::max();
  vector<int> candidates;
  for (int i = 1; i <= N; ++i) {
    int score = 0;
    for (int j = 1; j <= N; ++j) {
      score = max(score, distance_[i][j]);
    }
    if (min_score > score) {
      min_score = score;
      candidates = {i};
    } else if (min_score == score) {
      candidates.push_back(i);
    }
  }
  cout << min_score << ' ' << candidates.size() << '\n';
  for (const auto &candidate : candidates) {
    cout << candidate << ' ';
  }
  return 0;
}
