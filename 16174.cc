#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<bool>> visited(N, vector<bool>(N));
  queue<pair<int, int>> q;
  visited[0][0] = true;
  q.push({0, 0});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 2; ++i) {
      int x2 = x + dx[i] * vec[x][y];
      int y2 = y + dy[i] * vec[x][y];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N || visited[x2][y2]) {
        continue;
      }
      visited[x2][y2] = true;
      q.push({x2, y2});
    }
  }
  cout << (visited[N - 1][N - 1] ? "HaruHaru" : "Hing");
  return 0;
}
