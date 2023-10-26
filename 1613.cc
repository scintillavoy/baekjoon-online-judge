#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<vector<bool>> graph(n + 1, vector<bool>(n + 1));
  for (int i = 0; i < k; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from][to] = true;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }
  int s;
  cin >> s;
  for (int i = 0; i < s; ++i) {
    int from, to;
    cin >> from >> to;
    if (graph[from][to]) {
      cout << -1;
    } else if (graph[to][from]) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << '\n';
  }
  return 0;
}
