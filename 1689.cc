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
  vector<pair<int, int>> lines(N);
  for (int i = 0; i < N; ++i) {
    cin >> lines[i].first >> lines[i].second;
  }
  sort(lines.begin(), lines.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  int max_count = 0;
  for (int i = 0; i < N; ++i) {
    while (!pq.empty() && pq.top() <= lines[i].first) {
      pq.pop();
    }
    pq.push(lines[i].second);
    max_count = max(max_count, int(pq.size()));
  }
  cout << max_count;
  return 0;
}
