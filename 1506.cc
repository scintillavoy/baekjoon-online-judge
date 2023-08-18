#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> start_time;
int current_time = 0;
vector<int> lowest;
stack<int> s;
vector<int> scc_id;
int scc_count = 0;

void dfs(int curr) {
  start_time[curr] = ++current_time;
  lowest[curr] = start_time[curr];
  s.push(curr);
  for (const auto &adj : graph[curr]) {
    if (start_time[adj] == 0) {
      dfs(adj);
      lowest[curr] = min(lowest[curr], lowest[adj]);
    } else if (scc_id[adj] == 0) {
      lowest[curr] = min(lowest[curr], start_time[adj]);
    }
  }
  if (lowest[curr] == start_time[curr]) {
    ++scc_count;
    while (true) {
      int t = s.top();
      s.pop();
      scc_id[t] = scc_count;
      if (t == curr) break;
    }
  }
}

int main() {
  int N;
  cin >> N;
  graph = vector<vector<int>>(N);
  start_time = vector<int>(N);
  lowest = vector<int>(N);
  scc_id = vector<int>(N);
  vector<int> cost(N);
  for (auto &x : cost) {
    cin >> x;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      if (c == '1') {
        graph[i].push_back(j);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    if (start_time[i] != 0) continue;
    dfs(i);
  }
  vector<vector<int>> scc(scc_count);
  for (int i = 0; i < N; ++i) {
    scc[scc_id[i] - 1].push_back(i);
  }
  int sum = 0;
  for (const auto &component : scc) {
    int min_cost = numeric_limits<int>::max();
    for (const auto &x : component) {
      min_cost = min(min_cost, cost[x]);
    }
    sum += min_cost;
  }
  cout << sum;
  return 0;
}
