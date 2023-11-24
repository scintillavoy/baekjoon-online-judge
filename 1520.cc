#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int M, N;
vector<vector<int>> vec;
vector<vector<int>> routes;

int dfs(int x, int y) {
  if (x == M - 1 && y == N - 1) {
    return 1;
  }
  if (routes[x][y] != -1) {
    return routes[x][y];
  }
  routes[x][y] = 0;
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < 0 || x2 >= M || y2 < 0 || y2 >= N || vec[x2][y2] >= vec[x][y]) {
      continue;
    }
    routes[x][y] += dfs(x2, y2);
  }
  return routes[x][y];
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> M >> N;
  vec = vector<vector<int>>(M, vector<int>(N));
  routes = vector<vector<int>>(M, vector<int>(N, -1));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> vec[i][j];
    }
  }
  cout << dfs(0, 0);
  return 0;
}
