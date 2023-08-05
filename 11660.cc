#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(N));
  for (auto &row : vec) {
    for (auto &x : row) {
      cin >> x;
    }
  }
  for (int i = 1; i < N; ++i) {
    vec[0][i] += vec[0][i - 1];
    vec[i][0] += vec[i - 1][0];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      vec[i][j] += vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
    }
  }
  while (M--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    int answer = vec[x2][y2];
    if (x1 - 1 >= 0) {
      answer -= vec[x1 - 1][y2];
    }
    if (y1 - 1 >= 0) {
      answer -= vec[x2][y1 - 1];
    }
    if (x1 - 1 >= 0 && y1 - 1 >= 0) {
      answer += vec[x1 - 1][y1 - 1];
    }
    cout << answer << '\n';
  }
  return 0;
}
