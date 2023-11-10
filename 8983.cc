#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int M, N, L;
  cin >> M >> N >> L;
  vector<int> shoots(M);
  for (int i = 0; i < shoots.size(); ++i) {
    cin >> shoots[i];
  }
  vector<pair<int, int>> animals(N);
  for (int i = 0; i < animals.size(); ++i) {
    cin >> animals[i].first >> animals[i].second;
  }
  sort(shoots.begin(), shoots.end());
  int count = 0;
  for (int i = 0; i < animals.size(); ++i) {
    int diff = L - animals[i].second;
    if (diff < 0) {
      continue;
    }
    int x1 = animals[i].first - diff;
    int x2 = animals[i].first + diff;
    auto it = lower_bound(shoots.begin(), shoots.end(), x1);
    if (it != shoots.end() && *it <= x2) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
