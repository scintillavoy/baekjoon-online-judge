#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<int>> vec;

int get_safe_area() {
  vector<vector<int>> vec2 = vec;
  vector<vector<bool>> visited(N, vector<bool>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec[i][j] != 2 || visited[i][j]) {
        continue;
      }
      queue<pair<int, int>> q;
      visited[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M || vec[x2][y2] != 0 ||
              visited[x2][y2]) {
            continue;
          }
          vec2[x2][y2] = 2;
          visited[x2][y2] = true;
          q.push({x2, y2});
        }
      }
    }
  }
  int area = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (vec2[i][j] == 0) {
        ++area;
      }
    }
  }
  return area;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  vec = vector<vector<int>>(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
    }
  }
  int max_area = 0;
  for (int i = 0; i < N * M; ++i) {
    if (vec[i / M][i % M] != 0) {
      continue;
    }
    vec[i / M][i % M] = 1;
    for (int j = i + 1; j < N * M; ++j) {
      if (vec[j / M][j % M] != 0) {
        continue;
      }
      vec[j / M][j % M] = 1;
      for (int k = j + 1; k < N * M; ++k) {
        if (vec[k / M][k % M] != 0) {
          continue;
        }
        vec[k / M][k % M] = 1;
        max_area = max(max_area, get_safe_area());
        vec[k / M][k % M] = 0;
      }
      vec[j / M][j % M] = 0;
    }
    vec[i / M][i % M] = 0;
  }
  cout << max_area;
  return 0;
}
