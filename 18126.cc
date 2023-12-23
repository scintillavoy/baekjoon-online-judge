#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> graph(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    graph[A].push_back({B, C});
    graph[B].push_back({A, C});
  }
  vector<bool> visited(N + 1);
  queue<pair<int, long long>> q;
  visited[1] = true;
  q.push({1, 0});
  long long max_distance = 0;
  while (!q.empty()) {
    auto [curr, curr_distance] = q.front();
    q.pop();
    max_distance = max(max_distance, curr_distance);
    for (const auto& [adj, adj_weight] : graph[curr]) {
      if (visited[adj]) {
        continue;
      }
      visited[adj] = true;
      q.push({adj, (long long)curr_distance + adj_weight});
    }
  }
  cout << max_distance;
  return 0;
}
