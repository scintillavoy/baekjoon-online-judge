#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> distances(
      n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
  for (int i = 1; i <= n; ++i) {
    distances[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    distances[from][to] = weight;
    distances[to][from] = weight;
  }
  vector<vector<int>> successors(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j && distances[i][j] != numeric_limits<int>::max() / 2) {
        successors[i][j] = j;
      }
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (distances[i][j] > distances[i][k] + distances[k][j]) {
          distances[i][j] = distances[i][k] + distances[k][j];
          successors[i][j] = successors[i][k];
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (successors[i][j] == 0) {
        cout << '-';
      } else {
        cout << successors[i][j];
      }
      cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}
