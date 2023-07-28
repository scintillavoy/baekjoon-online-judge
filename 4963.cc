#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    vector<vector<int>> input(h, vector<int>(w));
    for (auto &row : input) {
      for (auto &x : row) {
        cin >> x;
      }
    }

    int count = 0;
    queue<pair<int, int>> bfs_queue;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (input[i][j] != 1) continue;
        ++count;
        bfs_queue.push({i, j});
        input[i][j] = 2;
        while (!bfs_queue.empty()) {
          auto curr = bfs_queue.front();
          bfs_queue.pop();
          for (int k = 0; k < 8; ++k) {
            pair<int, int> next(curr.first + dx[k], curr.second + dy[k]);
            if (next.first < 0 || next.first >= h || next.second < 0 ||
                next.second >= w || input[next.first][next.second] != 1) {
              continue;
            }
            bfs_queue.push(next);
            input[next.first][next.second] = 2;
          }
        }
      }
    }
    cout << count << '\n';
  }
  return 0;
}
