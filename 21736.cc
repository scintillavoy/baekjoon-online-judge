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
  vector<vector<char>> vec(N, vector<char>(M));
  pair<int, int> source;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
      if (vec[i][j] == 'I') {
        source = {i, j};
      }
    }
  }
  int count = 0;
  queue<pair<int, int>> bfs_queue;
  vec[source.first][source.second] = 'X';
  bfs_queue.push(source);
  while (!bfs_queue.empty()) {
    pair<int, int> current = bfs_queue.front();
    bfs_queue.pop();
    for (int i = 0; i < 4; ++i) {
      pair<int, int> adj{current.first + dx[i], current.second + dy[i]};
      if (adj.first < 0 || adj.first >= N || adj.second < 0 ||
          adj.second >= M || vec[adj.first][adj.second] == 'X') {
        continue;
      }
      if (vec[adj.first][adj.second] == 'P') {
        ++count;
      }
      vec[adj.first][adj.second] = 'X';
      bfs_queue.push(adj);
    }
  }
  if (count == 0) {
    cout << "TT";
  } else {
    cout << count;
  }
  return 0;
}
