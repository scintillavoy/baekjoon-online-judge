#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N + 1);
  vector<int> in_degree(N + 1);
  for (int i = 1; i <= M; ++i) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    ++in_degree[B];
  }
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> finished;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    finished.push_back(curr);
    for (const auto &adj : graph[curr]) {
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        q.push(adj);
      }
    }
  }
  for (const auto &x : finished) {
    cout << x << ' ';
  }
  return 0;
}
