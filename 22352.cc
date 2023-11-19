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
  vector<vector<int>> vec(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<int>> vec2(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec2[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec[i][j] == vec2[i][j]) {
        continue;
      }
      vector<vector<bool>> visited(N, vector<bool>(M));
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
              vec[x2][y2] != vec[x][y]) {
            continue;
          }
          visited[x2][y2] = true;
          q.push({x2, y2});
        }
        vec[x][y] = vec2[i][j];
      }
      goto out_of_loop;
    }
  }
out_of_loop:
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec[i][j] != vec2[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
