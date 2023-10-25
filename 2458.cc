#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> graph(N + 1, vector<bool>(N + 1));
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = true;
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }
  int answer = 0;
  for (int i = 1; i <= N; ++i) {
    int count = 0;
    for (int j = 1; j <= N; ++j) {
      if (graph[i][j]) {
        ++count;
      }
      if (graph[j][i]) {
        ++count;
      }
    }
    if (count == N - 1) {
      ++answer;
    }
  }
  cout << answer;
  return 0;
}
