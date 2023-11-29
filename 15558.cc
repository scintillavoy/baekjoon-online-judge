#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, k;
  cin >> N >> k;
  vector<vector<bool>> tiles(2, vector<bool>(N));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < N; ++j) {
      char input;
      cin >> input;
      tiles[i][j] = (input == '1' ? true : false);
    }
  }
  queue<tuple<int, int, int>> q;
  tiles[0][0] = false;
  q.push({0, 0, 0});
  while (!q.empty()) {
    auto [x, y, current_time] = q.front();
    q.pop();
    if (y + 1 >= N || y + k >= N) {
      cout << 1;
      return 0;
    }
    if (tiles[x][y + 1]) {
      tiles[x][y + 1] = false;
      q.push({x, y + 1, current_time + 1});
    }
    if (y - 1 >= 0 && tiles[x][y - 1] && y - 1 > current_time) {
      tiles[x][y - 1] = false;
      q.push({x, y - 1, current_time + 1});
    }
    if (tiles[x ^ 1][y + k]) {
      tiles[x ^ 1][y + k] = false;
      q.push({x ^ 1, y + k, current_time + 1});
    }
  }
  cout << 0;
  return 0;
}
