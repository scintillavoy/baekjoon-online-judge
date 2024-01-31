#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> distances(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> distances[i][j];
    }
  }
  vector<vector<bool>> valid_edge(N, vector<bool>(N, true));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (k == i || k == j) {
          continue;
        }
        if (distances[i][j] == distances[i][k] + distances[k][j]) {
          valid_edge[i][j] = false;
        } else if (distances[i][j] > distances[i][k] + distances[k][j]) {
          cout << -1;
          return 0;
        }
      }
    }
  }
  int sum_of_distances = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (valid_edge[i][j]) {
        sum_of_distances += distances[i][j];
      }
    }
  }
  cout << sum_of_distances / 2;
  return 0;
}
