#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<tuple<int, int, int>> vec(N);
  for (int i = 0; i < N; ++i) {
    int S, E, C;
    cin >> S >> E >> C;
    vec[i] = {S, E, C};
  }
  sort(vec.begin(), vec.end());
  vector<tuple<int, int, int>> vec_merged;
  auto [last_S, last_E, last_C] = vec[0];
  for (int i = 1; i < N; ++i) {
    auto [S, E, C] = vec[i];
    if (S > last_E) {
      vec_merged.push_back({last_S, last_E, last_C});
      last_S = S;
      last_E = E;
      last_C = C;
    } else {
      last_E = max(last_E, E);
      last_C = min(last_C, C);
    }
  }
  vec_merged.push_back({last_S, last_E, last_C});
  cout << vec_merged.size() << '\n';
  for (const auto [S, E, C] : vec_merged) {
    cout << S << ' ' << E << ' ' << C << '\n';
  }
  return 0;
}
