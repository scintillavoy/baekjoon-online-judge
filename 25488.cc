#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> scc_id;
int current_scc_id = 0;
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
    ++current_scc_id;
    while (true) {
      int t = s.top();
      s.pop();
      scc_id[t] = current_scc_id;
      if (t == curr) {
        break;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  graph = vector<vector<int>>(N + 1);
  scc_id = vector<int>(N + 1);
  start_time = vector<int>(N + 1);
  lowlink = vector<int>(N + 1);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  int P;
  cin >> P;
  vector<int> a(P), b(P);
  for (int i = 0; i < P; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < P; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= N; ++i) {
    if (start_time[i] == 0) {
      dfs(i);
    }
  }
  vector<int> scc_count(current_scc_id + 1);
  for (int i = 0; i < P; ++i) {
    ++scc_count[scc_id[a[i]]];
    --scc_count[scc_id[b[i]]];
  }
  for (int i = 0; i < scc_count.size(); ++i) {
    if (scc_count[i] != 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
