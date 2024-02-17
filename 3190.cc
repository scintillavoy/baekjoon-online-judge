#include <deque>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;

  vector<vector<int>> board(N, vector<int>(N));
  board[0][0] = 1;
  for (int i = 0; i < K; ++i) {
    int x, y;
    cin >> x >> y;
    board[x - 1][y - 1] = 2;
  }

  int L;
  cin >> L;
  deque<pair<int, char>> turns(L);
  for (int i = 0; i < L; ++i) {
    cin >> turns[i].first >> turns[i].second;
  }

  int time = 0;
  int direction = 1;
  deque<pair<int, int>> positions;
  positions.push_back({0, 0});

  while (true) {
    ++time;
    auto [x, y] = positions.back();
    int x2 = x + dx[direction];
    int y2 = y + dy[direction];
    if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N || board[x2][y2] == 1) {
      break;
    }
    positions.push_back({x2, y2});
    if (board[x2][y2] == 0) {
      pair<int, int> tail = positions.front();
      positions.pop_front();
      board[tail.first][tail.second] = 0;
    }
    board[x2][y2] = 1;

    if (!turns.empty() && turns.front().first == time) {
      char turn = turns.front().second;
      turns.pop_front();
      if (turn == 'L') {
        direction = (direction + 3) % 4;
      } else if (turn == 'D') {
        direction = (direction + 1) % 4;
      }
    }
  }

  cout << time;
  return 0;
}
