#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
      cin >> points[i].first >> points[i].second;
    }
    vector<bool> selected(N);
    for (int i = N / 2; i < N; ++i) {
      selected[i] = true;
    }
    double min_dist = numeric_limits<double>::max();
    do {
      double x = 0.0, y = 0.0;
      for (int i = 0; i < N; ++i) {
        if (selected[i]) {
          x += points[i].first;
          y += points[i].second;
        } else {
          x -= points[i].first;
          y -= points[i].second;
        }
      }
      min_dist = min(min_dist, sqrt(x * x + y * y));
    } while (next_permutation(selected.begin(), selected.end()));
    cout.precision(6);
    cout << fixed << min_dist << '\n';
  }
  return 0;
}
