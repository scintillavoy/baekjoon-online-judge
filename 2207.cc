#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

inline int index_of(int num) {
  if (num > 0) {
    return num * 2 - 1;
  }
  return -num * 2 - 2;
}

inline int not_of(int index) { return index ^ 1; }

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
  graph = vector<vector<int>>(M * 2);
  scc_id = vector<int>(M * 2);
  start_time = vector<int>(M * 2);
  lowlink = vector<int>(M * 2);
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    x = index_of(x);
    y = index_of(y);
    graph[not_of(x)].push_back(y);
    graph[not_of(y)].push_back(x);
  }
  for (int i = 0; i < graph.size(); ++i) {
    if (start_time[i] == 0) {
      dfs(i);
    }
  }
  for (int i = 1; i <= M; ++i) {
    if (scc_id[index_of(i)] == scc_id[index_of(-i)]) {
      cout << "OTL";
      return 0;
    }
  }
  cout << "^_^";
  return 0;
}
