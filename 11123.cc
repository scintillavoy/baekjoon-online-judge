#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (auto &row : grid) {
      for (auto &x : row) {
        cin >> x;
      }
    }
    int count = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] == '.') continue;
        grid[i][j] = '.';
        ++count;
        queue<pair<int, int>> bfs_queue;
        bfs_queue.push({i, j});
        while (!bfs_queue.empty()) {
          pair<int, int> current = bfs_queue.front();
          bfs_queue.pop();
          int x = current.first - 1, y = current.second;
          if (x >= 0 && grid[x][y] == '#') {
            grid[x][y] = '.';
            bfs_queue.push({x, y});
          }
          x = current.first, y = current.second - 1;
          if (y >= 0 && grid[x][y] == '#') {
            grid[x][y] = '.';
            bfs_queue.push({x, y});
          }
          x = current.first + 1, y = current.second;
          if (x < H && grid[x][y] == '#') {
            grid[x][y] = '.';
            bfs_queue.push({x, y});
          }
          x = current.first, y = current.second + 1;
          if (y < W && grid[x][y] == '#') {
            grid[x][y] = '.';
            bfs_queue.push({x, y});
          }
        }
      }
    }
    cout << count << '\n';
  }
  return 0;
}
