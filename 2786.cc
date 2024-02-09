#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> prices(N);
  for (int i = 0; i < N; ++i) {
    cin >> prices[i].first >> prices[i].second;
  }
  sort(prices.begin(), prices.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.second < b.second;
       });
  vector<int> A(N);
  A[N - 1] = prices[N - 1].first;
  for (int i = N - 2; i >= 0; --i) {
    A[i] = min(A[i + 1], prices[i].first);
  }
  long long sum = 0;
  int diff = numeric_limits<int>::max();
  for (int i = 0; i < N; ++i) {
    sum += prices[i].second;
    diff = min(diff, prices[i].first - prices[i].second);
    cout << min(sum + diff, sum - prices[i].second + A[i]) << '\n';
  }
  return 0;
}
