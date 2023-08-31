#include <iostream>
#include <limits>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int TC;
  cin >> TC;
  while (TC--) {
    int N, M, W;
    cin >> N >> M >> W;
    vector<long long> distance_(N + 1, 1e18);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; ++i) {
      int S, E, T;
      cin >> S >> E >> T;
      edges.push_back({S, E, T});
      edges.push_back({E, S, T});
    }
    for (int i = 0; i < W; ++i) {
      int S, E, T;
      cin >> S >> E >> T;
      edges.push_back({S, E, -T});
    }
    bool is_possible = false;
    for (int i = 1; i <= N; ++i) {
      for (const auto &edge : edges) {
        auto [from, to, weight] = edge;
        if (distance_[to] > distance_[from] + weight) {
          if (i == N) {
            is_possible = true;
          } else {
            distance_[to] = distance_[from] + weight;
          }
        }
      }
    }
    cout << (is_possible ? "YES" : "NO") << '\n';
  }
  return 0;
}
