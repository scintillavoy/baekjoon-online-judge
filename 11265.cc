#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> distances(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> distances[i][j];
    }
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        distances[i][j] =
            min(distances[i][j], distances[i][k] + distances[k][j]);
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (distances[A][B] <= C ? "Enjoy other party" : "Stay here") << '\n';
  }
  return 0;
}
