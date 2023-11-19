#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<bool>> visited(N, vector<bool>(M));
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (visited[i][j]) {
        continue;
      }
      bool is_peak = true;
      queue<pair<int, int>> q;
      visited[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 8; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) {
            continue;
          }
          if (vec[x2][y2] == vec[i][j]) {
            if (!visited[x2][y2]) {
              visited[x2][y2] = true;
              q.push({x2, y2});
            }
          } else if (vec[x2][y2] > vec[i][j]) {
            is_peak = false;
          }
        }
      }
      if (is_peak) {
        ++count;
      }
    }
  }
  cout << count;
  return 0;
}
