#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, source, destination, M;
  cin >> N >> source >> destination >> M;
  vector<long long> total_revenue(N, numeric_limits<long long>::min());
  vector<vector<pair<int, int>>> graph(N);
  for (int i = 0; i < M; ++i) {
    int from, to, price;
    cin >> from >> to >> price;
    graph[from].push_back({to, price});
  }
  vector<int> revenue(N);
  for (int i = 0; i < N; ++i) {
    cin >> revenue[i];
  }
  total_revenue[source] = revenue[source];
  queue<int> bfs_queue;
  for (int i = 0; i < N; ++i) {
    for (int from = 0; from < N; ++from) {
      if (total_revenue[from] == numeric_limits<long long>::min()) {
        continue;
      }
      for (const auto &adj : graph[from]) {
        auto [to, price] = adj;
        if (total_revenue[to] < total_revenue[from] - price + revenue[to]) {
          if (i == N - 1) {
            bfs_queue.push(from);
          }
          total_revenue[to] = total_revenue[from] - price + revenue[to];
        }
      }
    }
  }
  if (total_revenue[destination] == numeric_limits<long long>::min()) {
    cout << "gg";
  } else {
    vector<bool> visited(N);
    while (!bfs_queue.empty()) {
      int curr = bfs_queue.front();
      bfs_queue.pop();
      if (visited[curr]) {
        continue;
      }
      visited[curr] = true;
      for (const auto &adj : graph[curr]) {
        bfs_queue.push(adj.first);
      }
    }
    if (visited[destination]) {
      cout << "Gee";
    } else {
      cout << total_revenue[destination];
    }
  }
  return 0;
}
