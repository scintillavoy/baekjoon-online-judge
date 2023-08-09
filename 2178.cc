#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> vec(N, vector<bool>(M));
  for (auto &row : vec) {
    for (auto &&x : row) {
      char input;
      cin >> input;
      x = (input == '1');
    }
  }
  vector<vector<int>> distance(N, vector<int>(M));
  queue<pair<int, int>> bfs_queue;
  vec[0][0] = false;
  distance[0][0] = 1;
  bfs_queue.push({0, 0});
  while (!bfs_queue.empty()) {
    pair<int, int> curr = bfs_queue.front();
    bfs_queue.pop();
    if (curr == make_pair(N - 1, M - 1)) {
      cout << distance[curr.first][curr.second];
      return 0;
    }
    for (int i = 0; i < 4; ++i) {
      pair<int, int> next{curr.first + dx[i], curr.second + dy[i]};
      if (next.first < 0 || next.first >= N || next.second < 0 ||
          next.second >= M || !vec[next.first][next.second]) {
        continue;
      }
      vec[next.first][next.second] = false;
      distance[next.first][next.second] = distance[curr.first][curr.second] + 1;
      bfs_queue.push(next);
    }
  }
  return 0;
}
