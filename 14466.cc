#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, K, R;
  cin >> N >> K >> R;
  vector<vector<vector<pair<int, int>>>> roads(
      N + 1, vector<vector<pair<int, int>>>(N + 1));
  for (int i = 0; i < R; ++i) {
    int r, c, r2, c2;
    cin >> r >> c >> r2 >> c2;
    roads[r][c].push_back({r2, c2});
    roads[r2][c2].push_back({r, c});
  }
  vector<pair<int, int>> cows;
  for (int i = 0; i < K; ++i) {
    int r, c;
    cin >> r >> c;
    cows.push_back({r, c});
  }
  vector<vector<bool>> visited(N + 1, vector<bool>(N + 1));
  vector<int> counts;
  for (const auto &cow : cows) {
    if (visited[cow.first][cow.second]) {
      continue;
    }
    queue<pair<int, int>> q;
    int count = 1;
    visited[cow.first][cow.second] = true;
    q.push(cow);
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 <= 0 || x2 > N || y2 <= 0 || y2 > N || visited[x2][y2]) {
          continue;
        }
        bool flag = false;
        for (const auto &road : roads[x][y]) {
          if (road.first == x2 && road.second == y2) {
            flag = true;
            break;
          }
        }
        if (flag) {
          continue;
        }
        for (const auto &cow : cows) {
          if (cow.first == x2 && cow.second == y2) {
            ++count;
            break;
          }
        }
        visited[x2][y2] = true;
        q.push({x2, y2});
      }
    }
    counts.push_back(count);
  }
  int answer = 0;
  for (int i = 0; i < counts.size() - 1; ++i) {
    for (int j = i + 1; j < counts.size(); ++j) {
      answer += counts[i] * counts[j];
    }
  }
  cout << answer;
  return 0;
}
