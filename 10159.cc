#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<bool>> graph(N + 1, vector<bool>(N + 1));
  for (int i = 1; i <= N; ++i) {
    graph[i][i] = true;
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from][to] = true;
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    int count = 0;
    for (int j = 1; j <= N; ++j) {
      if (!graph[i][j] && !graph[j][i]) {
        ++count;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
