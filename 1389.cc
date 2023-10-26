#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> distance_(
      N + 1, vector<int>(N + 1, numeric_limits<int>::max() / 2));
  for (int i = 1; i <= N; ++i) {
    distance_[i][i] = 0;
  }
  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    distance_[A][B] = 1;
    distance_[B][A] = 1;
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (distance_[i][j] > distance_[i][k] + distance_[k][j]) {
          distance_[i][j] = distance_[i][k] + distance_[k][j];
        }
      }
    }
  }
  int min_count = numeric_limits<int>::max();
  int min_num = 0;
  for (int i = 1; i <= N; ++i) {
    int count = 0;
    for (int j = 1; j <= N; ++j) {
      count += distance_[i][j];
    }
    if (min_count > count) {
      min_count = count;
      min_num = i;
    }
  }
  cout << min_num;
  return 0;
}
