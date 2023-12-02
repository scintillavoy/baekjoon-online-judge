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
  int N, M;
  cin >> N >> M;
  vector<vector<char>> forest(N, vector<char>(M));
  vector<vector<int>> distances_from_tree(
      N, vector<int>(M, numeric_limits<int>::max()));
  queue<pair<int, int>> q;
  pair<int, int> V, J;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> forest[i][j];
      switch (forest[i][j]) {
        case '+':
          distances_from_tree[i][j] = 0;
          q.push({i, j});
          break;
        case 'V':
          V = {i, j};
          break;
        case 'J':
          J = {i, j};
          break;
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M ||
          distances_from_tree[x2][y2] != numeric_limits<int>::max()) {
        continue;
      }
      distances_from_tree[x2][y2] = distances_from_tree[x][y] + 1;
      q.push({x2, y2});
    }
  }
  vector<vector<int>> distances_from_V(
      N, vector<int>(M, numeric_limits<int>::min()));
  priority_queue<tuple<int, int, int>> pq;
  distances_from_V[V.first][V.second] = distances_from_tree[V.first][V.second];
  pq.push({distances_from_tree[V.first][V.second], V.first, V.second});
  while (!pq.empty()) {
    auto [curr_distance, x, y] = pq.top();
    pq.pop();
    if (distances_from_V[x][y] < curr_distance) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) {
        continue;
      }
      int next_distance = min(curr_distance, distances_from_tree[x2][y2]);
      if (distances_from_V[x2][y2] < next_distance) {
        distances_from_V[x2][y2] = next_distance;
        pq.push({distances_from_V[x2][y2], x2, y2});
      }
    }
  }
  cout << distances_from_V[J.first][J.second];
  return 0;
}
