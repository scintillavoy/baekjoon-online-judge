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
  vector<int> in_degree(N + 1);
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int X, Y, K;
    cin >> X >> Y >> K;
    graph[X].push_back({Y, K});
    ++in_degree[Y];
  }
  vector<int> counts(N + 1);
  queue<int> q;
  counts[N] = 1;
  q.push(N);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (const auto& [adj, weight] : graph[curr]) {
      counts[adj] += counts[curr] * weight;
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        q.push(adj);
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (graph[i].empty()) {
      cout << i << ' ' << counts[i] << '\n';
    }
  }
  return 0;
}
