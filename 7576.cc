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
  int M, N;
  cin >> M >> N;
  vector<vector<int>> vec(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
    }
  }
  queue<pair<int, int>> q;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec[i][j] == 1) {
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int x2 = x + dx[k];
      int y2 = y + dy[k];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M || vec[x2][y2] != 0) {
        continue;
      }
      vec[x2][y2] = vec[x][y] + 1;
      q.push({x2, y2});
    }
  }
  int days = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec[i][j] == 0) {
        cout << -1;
        return 0;
      }
      days = max(days, vec[i][j] - 1);
    }
  }
  cout << days;
  return 0;
}
