#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<int>> distances(n, vector<int>(n, numeric_limits<int>::max()));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  distances[0][0] = 0;
  pq.push({0, 0, 0});
  while (!pq.empty()) {
    auto [curr_distance, x, y] = pq.top();
    pq.pop();
    if (distances[x][y] < curr_distance) {
      continue;
    }
    for (int i = 0; i < 2; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 >= n || y2 >= n) {
        continue;
      }
      int adj_weight = max(0, vec[x2][y2] - vec[x][y] + 1);
      if (distances[x2][y2] > distances[x][y] + adj_weight) {
        distances[x2][y2] = distances[x][y] + adj_weight;
        pq.push({distances[x2][y2], x2, y2});
      }
    }
  }
  cout << distances.back().back();
  return 0;
}
