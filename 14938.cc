#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<int>> distances(
      n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
  for (int i = 1; i <= n; ++i) {
    distances[i][i] = 0;
  }
  vector<int> items(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> items[i];
  }
  for (int i = 1; i <= r; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    distances[a][b] = l;
    distances[b][a] = l;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        distances[i][j] =
            min(distances[i][j], distances[i][k] + distances[k][j]);
      }
    }
  }
  int max_count = 0;
  for (int i = 1; i <= n; ++i) {
    int count = 0;
    for (int j = 1; j <= n; ++j) {
      if (distances[i][j] <= m) {
        count += items[j];
      }
    }
    max_count = max(max_count, count);
  }
  cout << max_count;
  return 0;
}
