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
  cin >> noboolalpha;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      bool input;
      cin >> input;
      vec[i][j] = input;
    }
  }
  int total_time = 0;
  while (true) {
    vector<vector<int>> visited(N, vector<int>(M));
    queue<pair<int, int>> q;
    q.push({0, 0});
    ++visited[0][0];
    bool melted = false;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) {
          continue;
        }
        if (vec[x2][y2] == 1) {
          ++visited[x2][y2];
          if (visited[x2][y2] >= 2) {
            vec[x2][y2] = 0;
            melted = true;
          }
        }
        if (visited[x2][y2] != 0) {
          continue;
        }
        ++visited[x2][y2];
        q.push({x2, y2});
      }
    }
    if (!melted) {
      break;
    }
    ++total_time;
  }
  cout << total_time;
  return 0;
}
