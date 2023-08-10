#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
  int M, N, K;
  cin >> M >> N >> K;
  vector<vector<bool>> vec(N, vector<bool>(M, false));
  while (K--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; ++i) {
      for (int j = y1; j < y2; ++j) {
        vec[i][j] = true;
      }
    }
  }
  vector<int> areas;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec[i][j]) continue;
      int area = 0;
      queue<pair<int, int>> bfs_queue;
      vec[i][j] = true;
      ++area;
      bfs_queue.push({i, j});
      while (!bfs_queue.empty()) {
        pair<int, int> curr = bfs_queue.front();
        bfs_queue.pop();
        for (int i = 0; i < 4; ++i) {
          pair<int, int> next{curr.first + dx[i], curr.second + dy[i]};
          if (next.first < 0 || next.first >= N || next.second < 0 ||
              next.second >= M || vec[next.first][next.second]) {
            continue;
          }
          vec[next.first][next.second] = true;
          ++area;
          bfs_queue.push(next);
        }
      }
      areas.push_back(area);
    }
  }
  sort(areas.begin(), areas.end());
  cout << areas.size() << '\n';
  for (const auto &x : areas) {
    cout << x << ' ';
  }
  return 0;
}
