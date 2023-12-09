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
  vector<pair<int, int>> vec(N + 2);
  vec[0] = {600, 600};
  for (int i = 1; i < N + 1; ++i) {
    cin >> vec[i].first >> vec[i].second;
    vec[i].first = vec[i].first / 100 * 60 + vec[i].first % 100;
    vec[i].first = max(600, vec[i].first - 10);
    vec[i].second = vec[i].second / 100 * 60 + vec[i].second % 100;
    vec[i].second = min(1320, vec[i].second + 10);
  }
  vec[N + 1] = {1320, 1320};
  sort(vec.begin(), vec.end());
  int max_duration = 0;
  int last_time = 600;
  for (int i = 0; i < N + 2; ++i) {
    max_duration = max(max_duration, vec[i].first - last_time);
    last_time = max(last_time, vec[i].second);
  }
  cout << max_duration;
  return 0;
}
