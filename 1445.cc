#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> forest(N, vector<char>(M));
  vector<vector<pair<int, int>>> distance_(
      N, vector<pair<int, int>>(
             M, {numeric_limits<int>::max(), numeric_limits<int>::max()}));
  priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>,
                 greater<tuple<int, int, int, int>>>
      pq;
  pair<int, int> destination;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> forest[i][j];
      if (forest[i][j] == 'S') {
        distance_[i][j] = {0, 0};
        pq.push({0, 0, i, j});
      } else if (forest[i][j] == 'F') {
        destination = {i, j};
      }
    }
  }
  while (!pq.empty()) {
    auto [d1, d2, x, y] = pq.top();
    pq.pop();
    if (distance_[x][y] < make_pair(d1, d2)) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) {
        continue;
      }
      if (forest[x2][y2] == 'F') {
        if (distance_[x2][y2] > make_pair(d1, d2)) {
          distance_[x2][y2] = make_pair(d1, d2);
        }
        continue;
      }
      pair<int, int> weight = {0, 0};
      if (forest[x2][y2] == 'g') {
        weight.first = 1;
      } else {
        for (int j = 0; j < 4; ++j) {
          int x3 = x2 + dx[j];
          int y3 = y2 + dy[j];
          if (x3 < 0 || x3 >= N || y3 < 0 || y3 >= M) {
            continue;
          }
          if (forest[x3][y3] == 'g') {
            weight.second = 1;
            break;
          }
        }
      }
      pair<int, int> next_distance = {distance_[x][y].first + weight.first,
                                      distance_[x][y].second + weight.second};
      if (distance_[x2][y2] > next_distance) {
        distance_[x2][y2] = next_distance;
        pq.push({distance_[x2][y2].first, distance_[x2][y2].second, x2, y2});
      }
    }
  }
  pair<int, int> answer = distance_[destination.first][destination.second];
  cout << answer.first << ' ' << answer.second;
  return 0;
}
