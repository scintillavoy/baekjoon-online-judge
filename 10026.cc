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
  int N;
  cin >> N;
  vector<vector<char>> vec(N, vector<char>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<bool>> visited(N, vector<bool>(N));
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (visited[i][j]) {
        continue;
      }
      queue<pair<int, int>> q;
      ++count;
      visited[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N || visited[x2][y2] ||
              vec[x][y] != vec[x2][y2]) {
            continue;
          }
          visited[x2][y2] = true;
          q.push({x2, y2});
        }
        if (vec[x][y] == 'R') {
          vec[x][y] = 'G';
        }
      }
    }
  }
  cout << count;
  count = 0;
  visited = vector<vector<bool>>(N, vector<bool>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (visited[i][j]) {
        continue;
      }
      queue<pair<int, int>> q;
      ++count;
      visited[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N || visited[x2][y2] ||
              vec[x][y] != vec[x2][y2]) {
            continue;
          }
          visited[x2][y2] = true;
          q.push({x2, y2});
        }
      }
    }
  }
  cout << ' ' << count;
  return 0;
}
