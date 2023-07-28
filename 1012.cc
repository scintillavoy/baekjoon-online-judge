#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<int>> farm(M, vector<int>(N, 0));
    for (int i = 0; i < K; ++i) {
      int X, Y;
      cin >> X >> Y;
      farm[X][Y] = 1;
    }
    int count = 0;
    vector<vector<bool>> is_visited(M, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (farm[i][j] == 0 || is_visited[i][j]) continue;
        queue<pair<int, int>> bfs_queue;
        bfs_queue.push({i, j});
        is_visited[i][j] = true;
        ++count;
        while (!bfs_queue.empty()) {
          auto curr = bfs_queue.front();
          bfs_queue.pop();
          int x = curr.first - 1, y = curr.second;
          if (x >= 0 && farm[x][y] == 1 && !is_visited[x][y]) {
            bfs_queue.push({x, y});
            is_visited[x][y] = true;
          }
          x = curr.first, y = curr.second - 1;
          if (y >= 0 && farm[x][y] == 1 && !is_visited[x][y]) {
            bfs_queue.push({x, y});
            is_visited[x][y] = true;
          }
          x = curr.first + 1, y = curr.second;
          if (x < M && farm[x][y] == 1 && !is_visited[x][y]) {
            bfs_queue.push({x, y});
            is_visited[x][y] = true;
          }
          x = curr.first, y = curr.second + 1;
          if (y < N && farm[x][y] == 1 && !is_visited[x][y]) {
            bfs_queue.push({x, y});
            is_visited[x][y] = true;
          }
        }
      }
    }
    cout << count << '\n';
  }
  return 0;
}
