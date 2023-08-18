#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> start_time;
int current_time = 0;
vector<int> lowest;
stack<int> s;
vector<int> scc_num;
int scc_count = 0;

void dfs(int curr) {
  start_time[curr] = ++current_time;
  lowest[curr] = start_time[curr];
  s.push(curr);
  for (const auto &adj : graph[curr]) {
    if (start_time[adj] == 0) {
      dfs(adj);
      lowest[curr] = min(lowest[curr], lowest[adj]);
    } else if (scc_num[adj] == 0) {
      lowest[curr] = min(lowest[curr], start_time[adj]);
    }
  }
  if (lowest[curr] == start_time[curr]) {
    ++scc_count;
    while (true) {
      int t = s.top();
      s.pop();
      scc_num[t] = scc_count;
      if (t == curr) break;
    }
  }
}

int main() {
  int V, E;
  cin >> V >> E;
  graph = vector<vector<int>>(V + 1);
  start_time = vector<int>(V + 1);
  lowest = vector<int>(V + 1);
  scc_num = vector<int>(V + 1);
  for (int i = 0; i < E; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
  }
  for (int i = 1; i <= V; ++i) {
    if (start_time[i] != 0) continue;
    dfs(i);
  }
  vector<vector<int>> scc(scc_count);
  for (int i = 1; i <= V; ++i) {
    scc[scc_num[i] - 1].push_back(i);
  }
  for (int i = 0; i < scc.size(); ++i) {
    sort(scc[i].begin(), scc[i].end());
  }
  sort(scc.begin(), scc.end());
  cout << scc.size() << '\n';
  for (const auto &x : scc) {
    for (const auto &y : x) {
      cout << y << ' ';
    }
    cout << -1 << '\n';
  }
  return 0;
}
