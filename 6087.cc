#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  int W, H;
  cin >> W >> H;
  vector<vector<char>> vec(H, vector<char>(W));
  queue<pair<int, int>> q;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> vec[i][j];
      if (vec[i][j] == 'C') {
        q.push({i, j});
      }
    }
  }
  auto [dest_x, dest_y] = q.front();
  q.pop();
  vector<vector<int>> distance_(H, vector<int>(W, numeric_limits<int>::max()));
  auto [source_x, source_y] = q.front();
  distance_[source_x][source_y] = -1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x2 = x;
      int y2 = y;
      while (true) {
        x2 += dx[i];
        y2 += dy[i];
        if (x2 < 0 || x2 >= H || y2 < 0 || y2 >= W || vec[x2][y2] == '*') {
          break;
        }
        if (distance_[x2][y2] <= distance_[x][y] + 1) {
          continue;
        }
        distance_[x2][y2] = distance_[x][y] + 1;
        q.push({x2, y2});
      }
    }
  }
  distance_[source_x][source_y] = 0;
  cout << distance_[dest_x][dest_y];
  return 0;
}
