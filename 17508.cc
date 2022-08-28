#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> matrix(N);
  for (auto &row : matrix) {
    cin >> row;
  }
  if (N % 2 != 0 && M % 2 != 0 && matrix[N / 2][M / 2] != '8') {
    cout << -1;
    return 0;
  }
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      switch (matrix[i][j]) {
        case '6':
          if (matrix[N - i - 1][M - j - 1] == '6') {
            ++count;
          } else if (matrix[N - i - 1][M - j - 1] != '9') {
            cout << -1;
            return 0;
          }
          break;
        case '7':
          if (matrix[N - i - 1][M - j - 1] == '7') {
            ++count;
          } else {
            cout << -1;
            return 0;
          }
          break;
        case '8':
          if (matrix[N - i - 1][M - j - 1] != '8') {
            cout << -1;
            return 0;
          }
          break;
        case '9':
          if (matrix[N - i - 1][M - j - 1] == '9') {
            ++count;
          } else if (matrix[N - i - 1][M - j - 1] != '6') {
            cout << -1;
            return 0;
          }
          break;
      }
    }
  }
  cout << count / 2;
  return 0;
}
