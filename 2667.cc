#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  vector<vector<bool>> vec(N, vector<bool>(N));
  for (auto &row : vec) {
    for (auto &&x : row) {
      char input;
      cin >> input;
      x = (input == '1');
    }
  }
  vector<int> areas;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!vec[i][j]) continue;
      queue<pair<int, int>> bfs_queue;
      vec[i][j] = false;
      int area = 1;
      bfs_queue.push({i, j});
      while (!bfs_queue.empty()) {
        pair<int, int> curr = bfs_queue.front();
        bfs_queue.pop();
        for (int k = 0; k < 4; ++k) {
          pair<int, int> next{curr.first + dx[k], curr.second + dy[k]};
          if (next.first < 0 || next.first >= N || next.second < 0 ||
              next.second >= N || !vec[next.first][next.second]) {
            continue;
          }
          vec[next.first][next.second] = false;
          ++area;
          bfs_queue.push(next);
        }
      }
      areas.push_back(area);
    }
  }
  sort(areas.begin(), areas.end());
  cout << areas.size() << '\n';
  for (const auto &x : areas) {
    cout << x << '\n';
  }
  return 0;
}
