#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> build_time(N + 1);
  vector<vector<int>> graph(N + 1);
  vector<int> in_degree(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> build_time[i];
    while (true) {
      int adj;
      cin >> adj;
      if (adj == -1) break;
      graph[adj].push_back(i);
      ++in_degree[i];
    }
  }
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> finish_time(N + 1);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    finish_time[curr] += build_time[curr];
    for (const auto &adj : graph[curr]) {
      finish_time[adj] = max(finish_time[adj], finish_time[curr]);
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        q.push(adj);
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    cout << finish_time[i] << '\n';
  }
  return 0;
}
