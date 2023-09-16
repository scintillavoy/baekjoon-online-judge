#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> distance_(
      V + 1, vector<int>(V + 1, numeric_limits<int>::max() / 2));
  for (int i = 1; i <= V; ++i) {
    distance_[i][i] = 0;
  }
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    distance_[a][b] = c;
  }
  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        distance_[i][j] =
            min(distance_[i][j], distance_[i][k] + distance_[k][j]);
      }
    }
  }
  int min_distance = numeric_limits<int>::max() / 2;
  for (int i = 1; i <= V; ++i) {
    for (int j = i + 1; j <= V; ++j) {
      min_distance = min(min_distance, distance_[i][j] + distance_[j][i]);
    }
  }
  cout << (min_distance == numeric_limits<int>::max() / 2 ? -1 : min_distance);
  return 0;
}
