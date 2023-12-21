#include <deque>
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
outer_loop:
  while (T--) {
    int w, h;
    cin >> w >> h;
    vector<vector<char>> vec(h, vector<char>(w));
    vector<vector<int>> distances(h,
                                  vector<int>(w, numeric_limits<int>::max()));
    deque<tuple<int, int, char>> q;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> vec[i][j];
        if (vec[i][j] == '*') {
          q.push_front({i, j, vec[i][j]});
        } else if (vec[i][j] == '@') {
          distances[i][j] = 0;
          q.push_back({i, j, vec[i][j]});
        }
      }
    }
    while (!q.empty()) {
      auto [x, y, type] = q.front();
      q.pop_front();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= h || y2 < 0 || y2 >= w) {
          if (type == '@') {
            cout << distances[x][y] + 1 << '\n';
            goto outer_loop;
          }
          continue;
        }
        if (type == '*') {
          if (vec[x2][y2] == '#' || vec[x2][y2] == '*') {
            continue;
          }
          vec[x2][y2] = '*';
          q.push_back({x2, y2, '*'});
        } else if (type == '@') {
          if (vec[x2][y2] != '.') {
            continue;
          }
          vec[x2][y2] = '@';
          distances[x2][y2] = distances[x][y] + 1;
          q.push_back({x2, y2, '@'});
        }
      }
    }
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
