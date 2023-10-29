#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<bool>> graph(N, vector<bool>(N));
  cin >> noboolalpha;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      bool input;
      cin >> input;
      graph[i][j] = input;
    }
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << graph[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
