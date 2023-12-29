#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vec(n, vector<int>(m));
  int max_length = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == '1') {
        vec[i][j] = 1;
        max_length = 1;
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (vec[i][j] == 0) {
        continue;
      }
      vec[i][j] += min({vec[i - 1][j - 1], vec[i - 1][j], vec[i][j - 1]});
      max_length = max(max_length, vec[i][j]);
    }
  }
  cout << max_length * max_length;
  return 0;
}
