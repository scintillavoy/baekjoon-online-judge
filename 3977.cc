#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> start_time;
int current_time;
vector<int> lowlink;
stack<int> s;
vector<int> scc_id;
int scc_count;

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
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    graph = vector<vector<int>>(N);
    start_time = vector<int>(N);
    current_time = 0;
    lowlink = vector<int>(N);
    scc_id = vector<int>(N);
    scc_count = 0;
    for (int i = 0; i < M; ++i) {
      int A, B;
      cin >> A >> B;
      graph[A].push_back(B);
    }
    for (int i = 0; i < N; ++i) {
      if (start_time[i] == 0) {
        dfs(i);
      }
    }
    vector<int> in_degree(scc_count + 1);
    for (int from = 0; from < N; ++from) {
      for (const auto &to : graph[from]) {
        if (scc_id[from] != scc_id[to]) {
          ++in_degree[scc_id[to]];
        }
      }
    }
    int source_scc_id = 0;
    bool is_confusing = false;
    for (int i = 1; i < in_degree.size(); ++i) {
      if (in_degree[i] == 0) {
        if (source_scc_id != 0) {
          is_confusing = true;
          break;
        }
        source_scc_id = i;
      }
    }
    if (is_confusing) {
      cout << "Confused\n\n";
      continue;
    }
    for (int i = 0; i < graph.size(); ++i) {
      if (scc_id[i] == source_scc_id) {
        cout << i << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
