#include <deque>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> rooms(n, vector<int>(n));
  for (auto &row : rooms) {
    for (auto &room : row) {
      char type;
      cin >> type;
      room = (type == '0' ? 1 : 0);
    }
  }
  vector<vector<int>> distance_(n, vector<int>(n, numeric_limits<int>::max()));
  deque<pair<int, int>> dq;
  distance_[0][0] = 0;
  dq.push_front({0, 0});
  while (!dq.empty()) {
    auto [curr_x, curr_y] = dq.front();
    dq.pop_front();
    for (int i = 0; i < 4; ++i) {
      int next_x = curr_x + dx[i];
      int next_y = curr_y + dy[i];
      if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n ||
          distance_[next_x][next_y] <=
              distance_[curr_x][curr_y] + rooms[next_x][next_y]) {
        continue;
      }
      distance_[next_x][next_y] =
          distance_[curr_x][curr_y] + rooms[next_x][next_y];
      if (rooms[next_x][next_y] == 0) {
        dq.push_front({next_x, next_y});
      } else {
        dq.push_back({next_x, next_y});
      }
    }
  }
  cout << distance_[n - 1][n - 1];
  return 0;
}
