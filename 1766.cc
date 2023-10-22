#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N + 1);
  vector<int> in_degree(N + 1);
  while (M--) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    ++in_degree[B];
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= N; ++i) {
    if (in_degree[i] == 0) {
      pq.push(i);
    }
  }
  vector<int> finished;
  while (!pq.empty()) {
    int curr = pq.top();
    pq.pop();
    finished.push_back(curr);
    for (const auto &adj : graph[curr]) {
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        pq.push(adj);
      }
    }
  }
  for (const auto &x : finished) {
    cout << x << ' ';
  }
  return 0;
}
