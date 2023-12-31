#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

inline int index_of(int x) { return x > 0 ? x * 2 - 1 : -x * 2 - 2; }

inline int not_of(int index) { return index ^ 1; }

vector<vector<int>> graph;
vector<int> scc_id;
int current_scc_id;
vector<int> start_time;
int current_time;
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
outer_loop:
  while (cin >> N >> M) {
    graph = vector<vector<int>>(N * 2);
    scc_id = vector<int>(N * 2);
    current_scc_id = 0;
    start_time = vector<int>(N * 2);
    current_time = 0;
    lowlink = vector<int>(N * 2);
    for (int i = 0; i < M; ++i) {
      int a, b;
      cin >> a >> b;
      a = index_of(a);
      b = index_of(b);
      graph[not_of(a)].push_back(b);
      graph[not_of(b)].push_back(a);
    }
    for (int i = 0; i < graph.size(); ++i) {
      if (start_time[i] == 0) {
        dfs(i);
      }
    }
    for (int i = 1; i <= N; ++i) {
      if (scc_id[index_of(i)] == scc_id[index_of(-i)]) {
        cout << 0 << '\n';
        goto outer_loop;
      }
    }
    cout << 1 << '\n';
  }
  return 0;
}
