#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> is_visited(100'001, false);
  vector<int> distance(100'001);
  queue<int> bfs_queue;
  is_visited[N] = true;
  distance[N] = 0;
  bfs_queue.push(N);
  while (!bfs_queue.empty()) {
    int curr = bfs_queue.front();
    bfs_queue.pop();
    if (curr == K) {
      cout << distance[curr];
      return 0;
    }
    vector<int> next{curr - 1, curr + 1, curr * 2};
    for (const auto &x : next) {
      if (x < 0 || x > 100'000 || is_visited[x]) {
        continue;
      }
      is_visited[x] = true;
      distance[x] = distance[curr] + 1;
      bfs_queue.push(x);
    }
  }
  return 0;
}
