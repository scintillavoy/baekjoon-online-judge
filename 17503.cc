#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<int, int>> vec(K);
  for (auto &x : vec) {
    cin >> x.first >> x.second;
  }
  sort(vec.begin(), vec.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.second < b.second;
       });
  priority_queue<int, vector<int>, greater<int>> pq;
  int sum = 0;
  int level = 0;
  for (int i = 0; i < N; ++i) {
    pq.push(vec[i].first);
    sum += vec[i].first;
    level = max(level, vec[i].second);
  }
  for (int i = N; i < K; ++i) {
    if (sum >= M) break;
    int curr = pq.top();
    if (curr >= vec[i].first) continue;
    pq.pop();
    sum -= curr;
    pq.push(vec[i].first);
    sum += vec[i].first;
    level = max(level, vec[i].second);
  }
  cout << (sum < M ? -1 : level);
  return 0;
}
