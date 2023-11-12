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
  vector<vector<char>> vec(M, vector<char>(N));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> vec[i][j];
    }
  }
  int blue = 0, white = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (vec[i][j] == 'X') {
        continue;
      }
      int count = 0;
      char type = vec[i][j];
      queue<pair<int, int>> q;
      vec[i][j] = 'X';
      ++count;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k], y2 = y + dy[k];
          if (x2 < 0 || x2 >= M || y2 < 0 || y2 >= N || vec[x2][y2] != type) {
            continue;
          }
          vec[x2][y2] = 'X';
          ++count;
          q.push({x2, y2});
        }
      }
      if (type == 'B') {
        blue += count * count;
      } else {
        white += count * count;
      }
    }
  }
  cout << white << ' ' << blue;
  return 0;
}
