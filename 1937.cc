#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n;
vector<vector<int>> vec;
vector<vector<int>> distances;

int dfs(int x, int y) {
  if (distances[x][y] != 0) {
    return distances[x][y];
  }
  distances[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || vec[x][y] <= vec[x2][y2]) {
      continue;
    }
    distances[x][y] = max(distances[x][y], 1 + dfs(x2, y2));
  }
  return distances[x][y];
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n;
  vec = vector<vector<int>>(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> vec[i][j];
    }
  }
  distances = vector<vector<int>>(n, vector<int>(n));
  int max_distance = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      max_distance = max(max_distance, dfs(i, j));
    }
  }
  cout << max_distance;
  return 0;
}
