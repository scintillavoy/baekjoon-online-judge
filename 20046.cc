#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  vector<vector<int>> vec(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<int>> distances(m, vector<int>(n, numeric_limits<int>::max()));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  if (vec[0][0] != -1) {
    distances[0][0] = vec[0][0];
    pq.push({distances[0][0], 0, 0});
  }
  while (!pq.empty()) {
    auto [curr_distance, x, y] = pq.top();
    pq.pop();
    if (distances[x][y] < curr_distance) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || vec[x2][y2] == -1 ||
          distances[x2][y2] <= distances[x][y] + vec[x2][y2]) {
        continue;
      }
      distances[x2][y2] = distances[x][y] + vec[x2][y2];
      pq.push({distances[x2][y2], x2, y2});
    }
  }
  cout << (distances[m - 1][n - 1] == numeric_limits<int>::max()
               ? -1
               : distances[m - 1][n - 1]);
  return 0;
}
