#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> vec[i][j];
    }
  }
  int max_value = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (j + 3 < M) {
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i][j + 2] +
                                       vec[i][j + 3]);
      }
      if (i + 3 < N) {
        max_value = max(max_value, vec[i][j] + vec[i + 1][j] + vec[i + 2][j] +
                                       vec[i + 3][j]);
      }
      if (i + 1 < N && j + 1 < M) {
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i + 1][j] +
                                       vec[i + 1][j + 1]);
      }
      if (i + 2 < N && j + 1 < M) {
        max_value = max(max_value, vec[i][j] + vec[i + 1][j] + vec[i + 2][j] +
                                       vec[i + 2][j + 1]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i + 1][j + 1] + vec[i + 2][j + 1]);
        max_value = max(max_value, vec[i][j] + vec[i + 1][j] +
                                       vec[i + 1][j + 1] + vec[i + 2][j + 1]);
        max_value = max(max_value, vec[i][j] + vec[i + 1][j] +
                                       vec[i + 1][j + 1] + vec[i + 2][j]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i + 1][j] +
                                       vec[i + 2][j]);
      }
      if (i + 1 < N && j + 2 < M) {
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i][j + 2] +
                                       vec[i + 1][j + 1]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i][j + 2] +
                                       vec[i + 1][j]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i + 1][j + 1] + vec[i + 1][j + 2]);
        max_value = max(max_value, vec[i][j] + vec[i + 1][j] +
                                       vec[i + 1][j + 1] + vec[i + 1][j + 2]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i][j + 2] +
                                       vec[i + 1][j + 2]);
      }
      if (i - 1 >= 0 && j + 2 < M) {
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i - 1][j + 1] + vec[i - 1][j + 2]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i - 1][j + 1] + vec[i][j + 2]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] + vec[i][j + 2] +
                                       vec[i - 1][j + 2]);
      }
      if (i - 1 >= 0 && i + 1 < N && j + 1 < M) {
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i - 1][j + 1] + vec[i + 1][j + 1]);
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i - 1][j + 1] + vec[i + 1][j]);
      }
      if (i - 2 >= 0 && j + 1 < M) {
        max_value = max(max_value, vec[i][j] + vec[i][j + 1] +
                                       vec[i - 1][j + 1] + vec[i - 2][j + 1]);
      }
    }
  }
  cout << max_value;
  return 0;
}
