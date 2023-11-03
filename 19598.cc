#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> times(N);
  for (int i = 0; i < N; ++i) {
    cin >> times[i].first >> times[i].second;
  }
  sort(times.begin(), times.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  int count = 0;
  for (int i = 0; i < N; ++i) {
    while (!pq.empty() && pq.top() <= times[i].first) {
      pq.pop();
    }
    pq.push(times[i].second);
    count = max(count, (int)pq.size());
  }
  cout << count;
  return 0;
}
