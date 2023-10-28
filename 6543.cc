#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> start_time;
int current_time;
vector<int> scc_id;
int scc_count;
vector<int> lowlink;
stack<int> s;

void dfs(int curr) {
  start_time[curr] = ++current_time;
  lowlink[curr] = start_time[curr];
  s.push(curr);
  for (const auto &adj : graph[curr]) {
    if (start_time[adj] == 0) {
      dfs(adj);
      lowlink[curr] = min(lowlink[curr], lowlink[adj]);
    } else if (scc_id[adj] == 0) {
      lowlink[curr] = min(lowlink[curr], start_time[adj]);
    }
  }
  if (lowlink[curr] == start_time[curr]) {
    ++scc_count;
    while (true) {
      int t = s.top();
      s.pop();
      scc_id[t] = scc_count;
      if (t == curr) {
        break;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    graph = vector<vector<int>>(n + 1);
    start_time = vector<int>(n + 1);
    current_time = 0;
    scc_id = vector<int>(n + 1);
    scc_count = 0;
    lowlink = vector<int>(n + 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int v, w;
      cin >> v >> w;
      graph[v].push_back(w);
    }
    for (int i = 1; i <= n; ++i) {
      if (start_time[i] == 0) {
        dfs(i);
      }
    }
    vector<int> out_degree(scc_count + 1);
    for (int from = 1; from <= n; ++from) {
      for (const auto &to : graph[from]) {
        if (scc_id[from] != scc_id[to]) {
          ++out_degree[scc_id[from]];
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (out_degree[scc_id[i]] == 0) {
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
