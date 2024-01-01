#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
    }
  }
  for (int count = 0; true; ++count) {
    vector<vector<bool>> visited(N, vector<bool>(M));
    vector<vector<int>> next_vec(vec);
    bool found = false;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (vec[i][j] <= 0 || visited[i][j]) {
          continue;
        }
        if (found) {
          cout << count;
          return 0;
        }
        found = true;
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (vec[x2][y2] <= 0) {
              --next_vec[x][y];
            } else if (!visited[x2][y2]) {
              visited[x2][y2] = true;
              q.push({x2, y2});
            }
          }
        }
      }
    }
    if (!found) {
      break;
    }
    vec = next_vec;
  }
  cout << 0;
  return 0;
}
