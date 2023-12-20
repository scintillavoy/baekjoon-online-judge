#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> vec(N, vector<bool>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char c;
      cin >> c;
      vec[i][j] = (c == '1' ? true : false);
    }
  }
  vector<vector<vector<int>>> distances(
      N, vector<vector<int>>(M, vector<int>(2, numeric_limits<int>::max())));
  queue<tuple<int, int, bool>> q;
  distances[0][0][0] = 1;
  q.push({0, 0, false});
  while (!q.empty()) {
    auto [x, y, broke] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) {
        continue;
      }
      if (!vec[x2][y2] &&
          distances[x2][y2][broke] == numeric_limits<int>::max()) {
        distances[x2][y2][broke] = distances[x][y][broke] + 1;
        q.push({x2, y2, broke});
      } else if (vec[x2][y2] &&
                 distances[x2][y2][1] == numeric_limits<int>::max() && !broke) {
        distances[x2][y2][1] = distances[x][y][0] + 1;
        q.push({x2, y2, true});
      }
    }
  }
  int answer = min(distances[N - 1][M - 1][0], distances[N - 1][M - 1][1]);
  cout << (answer == numeric_limits<int>::max() ? -1 : answer);
  return 0;
}
