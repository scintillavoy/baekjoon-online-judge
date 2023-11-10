#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, G, K;
  cin >> N >> G >> K;
  vector<tuple<int, int, int>> ingredients(N);
  for (int i = 0; i < ingredients.size(); ++i) {
    int S, L, O;
    cin >> S >> L >> O;
    ingredients[i] = {S, L, O};
  }
  long long left = 0, right = 2'000'000'000;
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long total_count = 0;
    vector<long long> counts;
    for (int i = 0; i < ingredients.size(); ++i) {
      auto [S, L, O] = ingredients[i];
      long long count = (long long)S * max(1LL, mid - L);
      total_count += count;
      if (O == 1) {
        counts.push_back(count);
      }
    }
    sort(counts.begin(), counts.end());
    for (int i = 0; i < K && total_count > G && !counts.empty(); ++i) {
      total_count -= counts.back();
      counts.pop_back();
    }
    if (total_count > G) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left - 1;
  return 0;
}
