#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> scc_id;
int scc_count = 0;
vector<int> start_time;
int current_time = 0;
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
  int n, m;
  cin >> n >> m;
  graph = vector<vector<int>>(n + 1);
  scc_id = vector<int>(n + 1);
  start_time = vector<int>(n + 1);
  lowlink = vector<int>(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) {
    if (start_time[i] == 0) {
      dfs(i);
    }
  }
  vector<int> in_degree(scc_count + 1);
  for (int i = 1; i <= n; ++i) {
    for (const auto &adj : graph[i]) {
      if (scc_id[i] == scc_id[adj]) {
        continue;
      }
      ++in_degree[scc_id[adj]];
    }
  }
  int count = 0;
  for (int i = 1; i < in_degree.size(); ++i) {
    if (in_degree[i] == 0) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
