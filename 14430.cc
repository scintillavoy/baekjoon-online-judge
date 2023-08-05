#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(M));
  cin >> noboolalpha;
  for (auto &row : vec) {
    for (auto &x : row) {
      cin >> x;
    }
  }
  for (int i = 1; i < N; ++i) {
    vec[i][0] += vec[i - 1][0];
  }
  for (int i = 1; i < M; ++i) {
    vec[0][i] += vec[0][i - 1];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      vec[i][j] += max(vec[i - 1][j], vec[i][j - 1]);
    }
  }
  cout << vec[N - 1][M - 1];
  return 0;
}
