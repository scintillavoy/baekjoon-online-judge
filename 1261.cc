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
  int M, N;
  cin >> M >> N;
  vector<vector<int>> maze(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char x;
      cin >> x;
      maze[i][j] = x - '0';
    }
  }
  vector<vector<int>> distance_(N, vector<int>(M, numeric_limits<int>::max()));
  distance_[0][0] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  pq.push({0, 0, 0});
  while (!pq.empty()) {
    auto [curr_distance, curr_x, curr_y] = pq.top();
    pq.pop();
    if (distance_[curr_x][curr_y] < curr_distance) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      int next_x = curr_x + dx[i];
      int next_y = curr_y + dy[i];
      if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M ||
          distance_[next_x][next_y] <= curr_distance + maze[next_x][next_y]) {
        continue;
      }
      distance_[next_x][next_y] = curr_distance + maze[next_x][next_y];
      pq.push({distance_[next_x][next_y], next_x, next_y});
    }
  }
  cout << distance_[N - 1][M - 1];
  return 0;
}
