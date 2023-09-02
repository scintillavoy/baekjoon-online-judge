#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> graph(N);
  unordered_set<int> banned;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (a == 1 && i != N - 1) {
      banned.insert(i);
    }
  }
  for (int i = 0; i < M; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    if (banned.count(a) > 0 || banned.count(b) > 0) {
      continue;
    }
    graph[a].push_back({t, b});
    graph[b].push_back({t, a});
  }
  vector<long long> distance_(N, numeric_limits<long long>::max());
  distance_[0] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [curr_distance, curr] = pq.top();
    pq.pop();
    if (distance_[curr] < curr_distance) {
      continue;
    }
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distance_[adj] > curr_distance + adj_weight) {
        distance_[adj] = curr_distance + adj_weight;
        pq.push({distance_[adj], adj});
      }
    }
  }

  cout << (distance_[N - 1] == numeric_limits<long long>::max()
               ? -1
               : distance_[N - 1]);
  return 0;
}
