#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  vector<vector<char>> grid(R, vector<char>(C));
  for (auto &row : grid) {
    for (auto &x : row) {
      cin >> x;
    }
  }
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (grid[i][j] != 'S') continue;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || x >= R || y < 0 || y >= C) continue;
        if (grid[x][y] == '.') {
          grid[x][y] = 'D';
        } else if (grid[x][y] == 'W') {
          cout << 0;
          return 0;
        }
      }
    }
  }
  cout << 1 << '\n';
  for (const auto &row : grid) {
    for (const auto &x : row) {
      cout << x;
    }
    cout << '\n';
  }
  return 0;
}
