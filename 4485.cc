#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  for (int T = 1; true; ++T) {
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }
    vector<vector<int>> cave(N, vector<int>(N));
    for (auto &row : cave) {
      for (auto &x : row) {
        cin >> x;
      }
    }
    vector<vector<int>> distance_(N,
                                  vector<int>(N, numeric_limits<int>::max()));
    distance_[0][0] = cave[0][0];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    pq.push({distance_[0][0], 0, 0});
    while (!pq.empty()) {
      auto [curr_distance, curr_x, curr_y] = pq.top();
      pq.pop();
      if (distance_[curr_x][curr_y] < curr_distance) {
        continue;
      }
      for (int i = 0; i < 4; ++i) {
        int next_x = curr_x + dx[i];
        int next_y = curr_y + dy[i];
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N ||
            distance_[next_x][next_y] <= curr_distance + cave[next_x][next_y]) {
          continue;
        }
        distance_[next_x][next_y] = curr_distance + cave[next_x][next_y];
        pq.push({distance_[next_x][next_y], next_x, next_y});
      }
    }
    cout << "Problem " << T << ": " << distance_[N - 1][N - 1] << '\n';
  }
  return 0;
}
