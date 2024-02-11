#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const char direction[4] = {'L', 'R', 'U', 'D'};

vector<vector<char>> board;

tuple<int, int, int> move(int x, int y, int dx, int dy) {
  int dist = 0;
  while (board[x + dx][y + dy] != '#' && board[x][y] != 'O') {
    x += dx;
    y += dy;
    ++dist;
  }
  return {x, y, dist};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  board = vector<vector<char>>(N, vector<char>(M));
  tuple<int, int> red, blue;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        red = {i, j};
      } else if (board[i][j] == 'B') {
        blue = {i, j};
      }
    }
  }
  bool visited[10][10][10][10];
  fill_n(&visited[0][0][0][0], sizeof(visited) / sizeof(visited[0][0][0][0]),
         false);
  queue<tuple<int, int, int, int, string>> q;
  visited[get<0>(red)][get<1>(red)][get<0>(blue)][get<1>(blue)] = true;
  q.push({get<0>(red), get<1>(red), get<0>(blue), get<1>(blue), ""});
  while (!q.empty()) {
    auto [rx, ry, bx, by, directions] = q.front();
    q.pop();
    if (directions.size() >= 10) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      auto [rx2, ry2, r_dist] = move(rx, ry, dx[i], dy[i]);
      auto [bx2, by2, b_dist] = move(bx, by, dx[i], dy[i]);
      if (board[bx2][by2] == 'O') {
        continue;
      }
      if (board[rx2][ry2] == 'O') {
        directions += direction[i];
        cout << directions.size() << '\n';
        cout << directions;
        return 0;
      }
      if (rx2 == bx2 && ry2 == by2) {
        if (r_dist > b_dist) {
          rx2 -= dx[i];
          ry2 -= dy[i];
        } else {
          bx2 -= dx[i];
          by2 -= dy[i];
        }
      }
      if (visited[rx2][ry2][bx2][by2]) {
        continue;
      }
      visited[rx2][ry2][bx2][by2] = true;
      q.push({rx2, ry2, bx2, by2, directions + direction[i]});
    }
  }
  cout << -1;
  return 0;
}
