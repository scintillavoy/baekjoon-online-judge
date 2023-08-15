#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
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
  queue<int> q;
  vector<int> answer(N + 1);
  for (int i = 1; i <= N; ++i) {
    if (in_degree[i] > 0) continue;
    answer[i] = 1;
    q.push(i);
  }
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (const auto &adj : graph[curr]) {
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        answer[adj] = answer[curr] + 1;
        q.push(adj);
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    cout << answer[i] << ' ';
  }
  return 0;
}
