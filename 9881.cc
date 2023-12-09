#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> hills(N);
  for (int i = 0; i < N; ++i) {
    cin >> hills[i];
  }
  sort(hills.begin(), hills.end());
  int min_cost = numeric_limits<int>::max();
  for (int i = hills.front(); i <= hills.back(); ++i) {
    if (i + 17 > hills.back()) {
      break;
    }
    int cost = 0;
    for (int j = 0; j < N; ++j) {
      if (hills[j] < i) {
        cost += pow(i - hills[j], 2);
      } else if (hills[j] > i + 17) {
        cost += pow(i + 17 - hills[j], 2);
      }
    }
    min_cost = min(min_cost, cost);
  }
  cout << (min_cost == numeric_limits<int>::max() ? 0 : min_cost);
  return 0;
}
