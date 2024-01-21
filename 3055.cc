#include <deque>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int R, C;
  cin >> R >> C;
  vector<vector<char>> vec(R, vector<char>(C));
  deque<tuple<int, int, char, int>> dq;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> vec[i][j];
      if (vec[i][j] == '*') {
        dq.push_front({i, j, vec[i][j], 1});
      } else if (vec[i][j] == 'S') {
        dq.push_back({i, j, vec[i][j], 1});
      }
    }
  }
  while (!dq.empty()) {
    auto [x, y, type, distance] = dq.front();
    dq.pop_front();
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= R || y2 < 0 || y2 >= C || vec[x2][y2] == 'X') {
        continue;
      }
      if (type == '*') {
        if (vec[x2][y2] == '.' || vec[x2][y2] == 'S') {
          vec[x2][y2] = '*';
          dq.push_back({x2, y2, type, distance + 1});
        }
      } else if (type == 'S') {
        if (vec[x2][y2] == '.') {
          vec[x2][y2] = 'S';
          dq.push_back({x2, y2, type, distance + 1});
        } else if (vec[x2][y2] == 'D') {
          cout << distance;
          return 0;
        }
      }
    }
  }
  cout << "KAKTUS";
  return 0;
}
