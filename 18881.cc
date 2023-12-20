#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, bool>> vec(N);
  for (int i = 0; i < vec.size(); ++i) {
    int x, s;
    cin >> x >> s;
    vec[i] = {x, (s == 1 ? true : false)};
  }
  sort(vec.begin(), vec.end());
  int R = 1'000'000;
  for (int i = 0; i < vec.size(); ++i) {
    if (!vec[i].second) {
      continue;
    }
    if (i - 1 >= 0 && !vec[i - 1].second) {
      R = min(R, vec[i].first - vec[i - 1].first);
    }
    if (i + 1 < vec.size() && !vec[i + 1].second) {
      R = min(R, vec[i + 1].first - vec[i].first);
    }
  }
  int count = 0;
  int last_infected = -R;
  for (int i = 0; i < vec.size(); ++i) {
    if (!vec[i].second) {
      continue;
    }
    if (vec[i].first - last_infected >= R) {
      ++count;
    }
    last_infected = vec[i].first;
  }
  cout << count;
  return 0;
}
