#include <iostream>
#include <limits>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> distance_(N + 1, numeric_limits<long long>::max());
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < M; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    edges.push_back({C, A, B});
  }
  distance_[1] = 0;
  for (int i = 1; i <= N; ++i) {
    for (const auto &edge : edges) {
      auto [weight, from, to] = edge;
      if (distance_[from] == numeric_limits<long long>::max()) {
        continue;
      }
      if (distance_[to] > distance_[from] + weight) {
        if (i == N) {
          cout << -1;
          return 0;
        }
        distance_[to] = distance_[from] + weight;
      }
    }
  }
  for (int i = 2; i <= N; ++i) {
    if (distance_[i] == numeric_limits<long long>::max()) {
      cout << -1;
    } else {
      cout << distance_[i];
    }
    cout << '\n';
  }
  return 0;
}
