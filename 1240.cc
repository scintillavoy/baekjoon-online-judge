#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> graph(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    graph[from].push_back({weight, to});
    graph[to].push_back({weight, from});
  }
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    vector<int> distances(N + 1, -1);
    queue<int> q;
    distances[from] = 0;
    q.push(from);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto& [weight, adj] : graph[curr]) {
        if (distances[adj] != -1) {
          continue;
        }
        distances[adj] = distances[curr] + weight;
        q.push(adj);
      }
    }
    cout << distances[to] << '\n';
  }
  return 0;
}
