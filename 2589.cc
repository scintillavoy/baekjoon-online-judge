#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> vec(N, vector<bool>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char input;
      cin >> input;
      if (input == 'L') {
        vec[i][j] = true;
      }
    }
  }
  int max_distance = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (!vec[i][j]) {
        continue;
      }
      vector<vector<bool>> visited(N, vector<bool>(M));
      vector<vector<int>> distances(N, vector<int>(M));
      queue<pair<int, int>> q;
      visited[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M || visited[x2][y2] ||
              !vec[x2][y2]) {
            continue;
          }
          visited[x2][y2] = true;
          distances[x2][y2] = distances[x][y] + 1;
          max_distance = max(max_distance, distances[x2][y2]);
          q.push({x2, y2});
        }
      }
    }
  }
  cout << max_distance;
  return 0;
}
