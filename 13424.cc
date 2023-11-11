#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> distance_(
        N + 1, vector<int>(N + 1, numeric_limits<int>::max() / 2));
    for (int i = 1; i <= N; ++i) {
      distance_[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      distance_[a][b] = c;
      distance_[b][a] = c;
    }
    for (int k = 1; k <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          distance_[i][j] =
              min(distance_[i][j], distance_[i][k] + distance_[k][j]);
        }
      }
    }
    int K;
    cin >> K;
    vector<int> sources(K);
    for (int i = 0; i < K; ++i) {
      cin >> sources[i];
    }
    int min_distance = numeric_limits<int>::max();
    int room_number = 0;
    for (int i = 1; i <= N; ++i) {
      int total_distance = 0;
      for (int j = 0; j < K; ++j) {
        total_distance += distance_[sources[j]][i];
      }
      if (total_distance < min_distance) {
        min_distance = total_distance;
        room_number = i;
      }
    }
    cout << room_number << '\n';
  }
  return 0;
}
