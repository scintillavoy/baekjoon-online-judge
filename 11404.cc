#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> distance_(
      n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
  for (int i = 1; i <= n; ++i) {
    distance_[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    distance_[a][b] = min(distance_[a][b], c);
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        distance_[i][j] =
            min(distance_[i][j], distance_[i][k] + distance_[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (distance_[i][j] == numeric_limits<int>::max() / 2
                   ? 0
                   : distance_[i][j])
           << ' ';
    }
    cout << '\n';
  }
  return 0;
}
