#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> D(N + 1);
    for (int i = 1; i <= N; ++i) {
      cin >> D[i];
    }
    vector<vector<int>> graph(N + 1);
    vector<int> in_degree(N + 1);
    for (int i = 0; i < K; ++i) {
      int X, Y;
      cin >> X >> Y;
      graph[X].push_back(Y);
      ++in_degree[Y];
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
      if (in_degree[i] != 0) continue;
      q.push(i);
    }
    vector<int> min_time(N + 1);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      min_time[curr] += D[curr];
      for (const auto &adj : graph[curr]) {
        min_time[adj] = max(min_time[adj], min_time[curr]);
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q.push(adj);
        }
      }
    }
    int W;
    cin >> W;
    cout << min_time[W] << '\n';
  }
  return 0;
}
