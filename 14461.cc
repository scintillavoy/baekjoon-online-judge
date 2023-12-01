#include <algorithm>
#include <functional>
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
  int N, T;
  cin >> N >> T;
  vector<vector<int>> vec(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> vec[i][j];
    }
  }
  vector<vector<vector<long long>>> distances(
      N, vector<vector<long long>>(
             N, vector<long long>(3, numeric_limits<long long>::max())));
  priority_queue<tuple<long long, int, int, int>,
                 vector<tuple<long long, int, int, int>>,
                 greater<tuple<long long, int, int, int>>>
      q;
  distances[0][0][0] = 0;
  q.push({0, 0, 0, 0});
  while (!q.empty()) {
    auto [curr_distance, x, y, count] = q.top();
    q.pop();
    if (distances[x][y][count] < curr_distance) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N) {
        continue;
      }
      long long next_distance = distances[x][y][count] + T;
      long long next_count = (count + 1) % 3;
      if (next_count == 0) {
        next_distance += vec[x2][y2];
      }
      if (distances[x2][y2][next_count] > next_distance) {
        distances[x2][y2][next_count] = next_distance;
        q.push({next_distance, x2, y2, next_count});
      }
    }
  }
  cout << *min_element(distances[N - 1][N - 1].cbegin(),
                       distances[N - 1][N - 1].cend());
  return 0;
}
